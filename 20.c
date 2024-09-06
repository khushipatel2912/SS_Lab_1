/*
Name : 20.c
Author : Khushi Patel
Description :Find out the priority of your running program. Modify the priority with nice command.
Date: 31st Aug, 2024

*/


#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    int priority = getpriority(PRIO_PROCESS, 0);
    if (priority == -1 && errno != 0) {
        perror("getpriority");
        return 1;
    }

    printf("Current Priority: %d\n", priority);
    return 0;
}




/*

Output:


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./20 &
[1] 5964
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ Current Priority: 0

[1]+  Done                    ./20
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ps -o pid,ni,pri,comm -p 5964
    PID  NI PRI COMMAND


*/
