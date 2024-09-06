/*
Name : 10.c
Author : Khushi Patel
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 31st Aug, 2024

*/


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("seektest.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (write(fd, "HelloWorld", 10) != 10) {
        perror("write");
        return 1;
    }

    off_t offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("lseek");
        return 1;
    }

    if (write(fd, "HelloAgain", 10) != 10) {
        perror("write");
        return 1;
    }

    close(fd);
    return 0;
}



/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./10
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat seektest.txt
Hello WorlHello Agaikhushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ od -c seektest.txt
0000000   H   e   l   l   o       W   o   r   l  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   H   e   l   l   o       A   g   a   i
0000036


*/
