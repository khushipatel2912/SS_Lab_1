/*
Name : 16b.c
Author : Khushi Patel
Description :Write a program to perform mandatory locking.
a. Implement read lock
Date: 31st Aug, 2024

*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("f8.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        return 1;
    }

    printf("Read lock acquired.\n");
    printf("Press Enter to release lock");
    getchar();  

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released.\n");
    close(fd);

    return 0;
}




/*

Output:


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./16b 
Read lock acquired.
Press Enter to release lock
Read lock released.


*/
