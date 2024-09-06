/*
Name : 30.c
Author : Khushi Patel
Description :Write a program to run a script at a specific time using a Daemon process.
Date: 31st Aug, 2024

*/




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void create_daemon() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);  
    }

    if (setsid() < 0) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") < 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        if (t->tm_hour == 12 && t->tm_min == 0) {
            system("/path/to/script.sh");
        }
        sleep(60);  
    }
}

int main() {
    create_daemon();
    return 0;
}

/*

Output:
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./30
This script file is executed at 10:00pm 



*/
