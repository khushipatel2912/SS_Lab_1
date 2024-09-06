/*
Name : 23.c
Author : Khushi Patel
Description :Write a program to create a Zombie state of the running program.
Date: 31st Aug, 2024

*/



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process exiting...\n");
        _exit(0);
    } else {
        sleep(10);
        wait(NULL); 
    }

    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./23
Child process exiting...


*/
