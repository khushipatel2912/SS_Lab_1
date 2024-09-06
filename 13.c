/*
Name : 13.c
Author : Khushi Patel
Description :Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31st Aug, 2024

*/



#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    int result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
    } else if (result == 0) {
        printf("No input within 10 seconds.\n");
    } else {
        printf("Data is available!\n");
    }

    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 13.c -o 13
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./13
Waiting for input for 10 seconds...
No input within 10 seconds.


*/
