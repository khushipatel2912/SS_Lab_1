/*
Name : 7.c
Author : Khushi Patel
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 31st Aug, 2024

*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("open");
        return 1;
    }

    int dst_fd = creat(argv[2], 0644);
    if (dst_fd < 0) {
        perror("creat");
        close(src_fd);
        return 1;
    }

    char buffer[1024];
    ssize_t n;
    while ((n = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dst_fd, buffer, n);
    }

    close(src_fd);
    close(dst_fd);
    return 0;
}


/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat f7a.txt
Read File

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./7 f7a.txt f7b.txt
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat f7b.txt
Read File


*/
