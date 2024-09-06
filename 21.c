/*
Name : 21.c
Author : Khushi Patel
Description :Write a program, call fork and print the parent and child process id.
Date: 31st Aug, 2024

*/



#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process ID: %d\n", getpid());
    } else {
        // Parent process
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}



/*

Output:


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 21.c -o 21
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./21
Parent Process ID: 6141
Child Process ID: 6142
Child Process ID: 6142



*/
