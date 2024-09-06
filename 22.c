/*
Name : 22.c
Author : Khushi Patel
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 31st Aug, 2024

*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("f9.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        write(fd, "Child was here\n", 15);
    } else {
        write(fd, "Parent was here\n", 16);
    }

    close(fd);
    return 0;
}



/*

Output:


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 22.c -o 22
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./22
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat f9.txt
Parent was here
Child was here




*/
