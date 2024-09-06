/*
Name : 12.c
Author : Khushi Patel
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 31st Aug, 2024

*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s f8.txt\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        return 1;
    }

    int accessMode = flags & O_ACCMODE;

    switch (accessMode) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
        default:
            printf("Unknown mode.\n");
    }

    close(fd);
    return 0;
}




/*

Output:
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 12.c -o 12
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./12 f8.txt
File is opened in read-only mode.


*/
