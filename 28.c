/*
Name : 28.c
Author : Khushi Patel
Description :Write a program to get maximum and minimum real time priority.
Date: 31st Aug, 2024

*/



#include <stdio.h>
#include <sched.h>

int main() {
    int min_priority = sched_get_priority_min(SCHED_RR);
    int max_priority = sched_get_priority_max(SCHED_RR);

    if (min_priority == -1 || max_priority == -1) {
        perror("sched_get_priority");
        return 1;
    }

    printf("Minimum Real-Time Priority: %d\n", min_priority);
    printf("Maximum Real-Time Priority: %d\n", max_priority);

    return 0;
}






/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 28.c -o 28
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./28
Minimum Real-Time Priority: 1
Maximum Real-Time Priority: 99


*/
