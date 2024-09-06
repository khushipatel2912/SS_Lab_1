/*
Name : 18b.c
Author : Khushi Patel
Description :Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 31st Aug, 2024

*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    int id;
    char data[100];
} Record;

int main() {
    int fd = open("f8.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = sizeof(Record);  
    lock.l_len = sizeof(Record);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        return 1;
    }

    Record rec;
    lseek(fd, sizeof(Record), SEEK_SET);  
    read(fd, &rec, sizeof(rec));
    printf("Read Record ID: %d\n", rec.id);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 18a.c -o 18a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./18a
Current Record ID: 1769169250

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 18b.c -o 18b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./18b
Read Record ID: 999

*/
