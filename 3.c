/*
Name : 3.c
Author : Khushi Patel
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 31st Aug, 2024

*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = creat("f3.txt", 0644);
    if (fd < 0) {
        perror("creat");
        return 1;
    }
    printf("File descriptor: %d\n", fd);
    close(fd);
    return 0;
}

/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 3.c -o createfile
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./createfile
File descriptor: 3
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ls
1a  1a.c  1b  1b.c  1c  1c.c  2  2.c  3.c  createfile  f1a.txt  f1.txt  f2.txt  f3.txt  fifofile1  fifofile2  hardlink1.txt  hardlink.txt  README.md  symlink1  symlink1a


*/
