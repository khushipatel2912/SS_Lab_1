/*
Name : 25.c
Author : Khushi Patel
Description :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31st Aug, 2024

*/




#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 == 0) {
        sleep(1);  
        return 1;
    }

    pid2 = fork();
    if (pid2 == 0) {
        sleep(2); 
        return 2;
    }

    pid3 = fork();
    if (pid3 == 0) {
        sleep(3);  
        return 3;
    }

    int status;
    pid_t waited_pid = waitpid(pid2, &status, 0);
    if (WIFEXITED(status)) {
        printf("Child with PID %d exited with status %d\n", waited_pid, WEXITSTATUS(status));
    }

    return 0;
}





/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 25.c -o 25
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./25
Child with PID 6613 exited with status 2


*/
