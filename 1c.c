/*
Name : 1c.c
Author : Khushi Patel
Description : Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024

Output:

Using Shell Command

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ mkfifo /home/khushi/my-repo/fifofile1
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ls -l /home/khushi/my-repo/fifofile1
prw-rw-r-- 1 khushi khushi 0 Aug 31 17:11 /home/khushi/my-repo/fifofile1

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    if (mkfifo("/home/khushi/my-repo/fifofile2", 0666) == 0) {
        printf("FIFO CREATED SUCCESSFULLY.\n");
    } else {
        perror("mkfifo");
    }
    return 0;
}

/*
Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./1c
FIFO CREATED SUCCESSFULLY.

*/
