/*
Name : 8.c
Author : Khushi Patel
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 31st Aug, 2024

*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s f8.txt \n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t n;
    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }

    if (n < 0) {
        perror("read");
    }

    close(fd);
    return 0;
}



/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 8.c -o 8
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./8 f8.txt
A kernel is the essential foundation of a computer's operating system (OS). It's the core that provides basic services for all other parts of the OS. It's the main layer between the OS and underlying computer hardware, and it helps with tasks such as process and memory management, inter-process communication, file system management, device control and networking.

During normal system startup, a computer's basic input/output system, or BIOS, completes a hardware bootstrap or initialization. It then runs a bootloader which loads the kernel from a storage device -- such as a hard drive -- into a protected memory space. Once the kernel is loaded into computer memory, the BIOS transfers control to the kernel. It then loads other OS components to complete the system startup and make control available to users through a desktop or other user interface.



*/
