/*
Name : 29.c
Author : Khushi Patel
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 31st Aug, 2024

*/



#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current Scheduling Policy: %d\n", policy);

    struct sched_param param;
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to FIFO with max priority.\n");

    return 0;
}






/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 29.c -o 29
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ sudo ./29
[sudo] password for khushi: 
Current Scheduling Policy: 0
Scheduling policy changed to FIFO with max priority.



*/
