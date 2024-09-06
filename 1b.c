/*
Name : 1b.c
Author : Khushi Patel
Description : Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 31st Aug, 2024.


Output:

Using Shell Command

-rw-rw-r-- 2 khushi khushi   0 Aug 31 16:38 hardlink.txt
-rw-rw-r-- 2 khushi khushi   0 Aug 31 16:38 f2.txt

Using System Call

*/


#include <unistd.h>
#include <stdio.h>

int main() {
    if (link("/home/khushi/my-repo/f2a.txt", "/home/khushi/my-repo/hardlink1.txt") == 0) {
        printf("HARD lINK CREATED.\n");
    } else {
        perror("link");
    }
    return 0;
}


/*
Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat f2a.txt 
Hardlink Created

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat hardlink1.txt 
Hardlink Created


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ rm f2a.txt
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat hardlink1.txt 
Hardlink Created

*/
