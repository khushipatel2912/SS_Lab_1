/*
Name : 16a.c
Author : Khushi Patel
Description :Write a program to perform mandatory locking.
a. Implement write lock
Date: 31st Aug, 2024

*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("f8.txt", O_WRONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        return 1;
    }

    printf("Write lock acquired.\n");
    printf("Press Enter to release lock");
    getchar(); 
    
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");
    close(fd);

    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./16a
Write lock acquired.
Press Enter to release lock
Write lock released.


*/
