/*
Name : 19.c
Author : Khushi Patel
Description :Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 31st Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;

    start = rdtsc();
    getpid();
    end = rdtsc();

    printf("Time taken by getpid(): %lu cycles\n", end - start);
    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./19
Time taken by getpid(): 12088 cycles


*/
