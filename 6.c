/*
Name : 6.c
Author : Khushi Patel
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 31st Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t n;

    while ((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }

    if (n < 0) {
        perror("read");
        return 1;
    }

    return 0;
}



/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 6.c -o 6
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./6
STDIN 10
STDIN 10

*/
