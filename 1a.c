/* 

Name : 1a.c
Author : Khushi Patel
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 31st Aug, 2024.


Using Shell Command:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~$ ln -s f1.txt symlink1
lrwxrwxrwx 1 khushi khushi    6 Aug 31 13:06  symlink1 -> f1.txt


Using System Call
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    if (symlink("/home/khushi/my-repo/f1a.txt", "/home/khushi/my-repo/symlink1a") == 0) {
        printf("SOFT lINK CREATED\n");
    } else {
        perror("symlink");
    }
    return 0;
}

/*

Output:
lrwxrwxrwx 1 khushi khushi   7 Aug 31 15:58 symlink1a -> f1a.txt
*/
