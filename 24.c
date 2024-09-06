/*
Name : 24.c
Author : Khushi Patel
Description :Write a program to create an orphan process.
Date: 31st Aug, 2024

*/




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process running with parent ID: %d\n", getppid());
        sleep(5);
        printf("Child process running with new parent ID: %d\n", getppid());
    } else {
        printf("Parent process exiting...\n");
        exit(0);
    }

    return 0;
}




/*

Output:


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 24.c -o 24
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./24
Parent process exiting...
Child process running with parent ID: 6522


*/
