/*
Name : 17b.c
Author : Khushi Patel
Description :Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31st Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int main() {
    int fd = open("tkt.txt", O_RDWR);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (flock(fd, LOCK_EX) == -1) {
        perror("Error locking file");
        close(fd);
        return 1;
    }

    int ticket_number;
    FILE *file = fdopen(fd, "r+");
    if (file == NULL) {
        perror("Error opening file stream");
        flock(fd, LOCK_UN);
        close(fd);
        return 1;
    }

    fscanf(file, "%d", &ticket_number);
    ticket_number++; 


    fseek(file, 0, SEEK_SET);
    fprintf(file, "%d\n", ticket_number);
    fflush(file);

    printf("New ticket number: %d\n", ticket_number);

    flock(fd, LOCK_UN);
    fclose(file);
    close(fd);

    return 0;
}


/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 17a.c -o 17a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./17a
Ticket number 1000 stored in file.


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 17b.c -o 17b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./17b
New ticket number: 1001



*/
