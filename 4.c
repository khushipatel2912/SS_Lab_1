/*
Name : 4.c
Author : Khushi Patel
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 31st Aug, 2024

*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("f4.txt", O_RDWR | O_EXCL);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    printf("File opened with descriptor %d\n", fd);
    close(fd);
    return 0;
}

/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 4.c -o openfile
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./openfile
File opened with descriptor 3
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ls
1a    1b    1c    2    3.c  createfile  f1.txt  f3.txt  fifofile1  hardlink1.txt  openfile   symlink1
1a.c  1b.c  1c.c  2.c  4.c  f1a.txt     f2.txt  f4.txt  fifofile2  hardlink.txt   README.md  symlink1a

*/
