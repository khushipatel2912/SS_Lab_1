/*
Name : 17a.c
Author : Khushi Patel
Description :Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31st Aug, 2024

*/




#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("tkt.txt", "w");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ticket_number = 1000; 
    fprintf(file, "%d\n", ticket_number);

    fclose(file);
    printf("Ticket number %d stored in file.\n", ticket_number);
    return 0;
}


/*

Output:


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 17a.c -o 17a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./17a
Ticket number 1000 stored in file.



*/
