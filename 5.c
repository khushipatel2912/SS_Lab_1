/*
Name : 5.c
Author : Khushi Patel
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 31st Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];
    char f5[20];

    for (int i = 0; i < 5; i++) {
        sprintf(f5, "file%d.txt", i + 1);
        fd[i] = open(f5, O_CREAT | O_WRONLY, 0644);
        if (fd[i] < 0) {
            perror("Error creating file");
            exit(1);
        }
    }

    while (1) {
        sleep(1); 
    }

    for (int i = 0; i < 5; i++) {
        close(fd[i]);
    }

    return 0;
}



/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 5.c -o createfiles
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./createfiles &
[1] 29610
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ls -l /proc/29610/fd
total 0
lrwx------ 1 khushi khushi 64 Aug 31 18:40 0 -> /dev/pts/1
lrwx------ 1 khushi khushi 64 Aug 31 18:40 1 -> /dev/pts/1
lrwx------ 1 khushi khushi 64 Aug 31 18:40 2 -> /dev/pts/1
l-wx------ 1 khushi khushi 64 Aug 31 18:40 3 -> /home/khushi/my-repo/file1.txt
l-wx------ 1 khushi khushi 64 Aug 31 18:40 4 -> /home/khushi/my-repo/file2.txt
l-wx------ 1 khushi khushi 64 Aug 31 18:40 5 -> /home/khushi/my-repo/file3.txt
l-wx------ 1 khushi khushi 64 Aug 31 18:40 6 -> /home/khushi/my-repo/file4.txt
l-wx------ 1 khushi khushi 64 Aug 31 18:40 7 -> /home/khushi/my-repo/file5.txt

*/
