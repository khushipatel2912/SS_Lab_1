/*
Name : 11.c
Author : Khushi Patel
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 31st Aug, 2024

*/


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd1 = open("f8.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd1 < 0) {
        perror("open");
        return 1;
    }

    int fd2 = dup(fd1);
    int fd3 = dup2(fd1, 7);

    write(fd1, "Writing to fd1\n", 15);
    write(fd2, "Writing to fd2\n", 15);
    write(fd3, "Writing to fd3\n", 15);

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 11.c -o 11
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./11 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat f8.txt
A kernel is the essential foundation of a computer's operating system (OS). It's the core that provides basic services for all other parts of the OS. It's the main layer between the OS and underlying computer hardware, and it helps with tasks such as process and memory management, inter-process communication, file system management, device control and networking.

During normal system startup, a computer's basic input/output system, or BIOS, completes a hardware bootstrap or initialization. It then runs a bootloader which loads the kernel from a storage device -- such as a hard drive -- into a protected memory space. Once the kernel is loaded into computer memory, the BIOS transfers control to the kernel. It then loads other OS components to complete the system startup and make control available to users through a desktop or other user interface.
Writing to fd1
Writing to fd2
Writing to fd3


*/
