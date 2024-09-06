/*
Name : 26.c
Author : Khushi Patel
Description :26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31st Aug, 2024

*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/home/khushi/my-repo/9", "f8.txt", NULL};

    if (execvp(args[0], args) == -1) {
        perror("execvp failed");
        exit(1);
    }


    return 0;

}





/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 26.c -o 26
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./26
Inode: 6836333
Number of hard links: 1
UID: 1000
GID: 1000
Size: 966 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Sat Aug 31 23:05:12 2024
Time of last modification: Sat Aug 31 23:05:08 2024
Time of last status change: Sat Aug 31 23:05:08 2024


*/
