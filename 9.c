/*
Name : 9.c
Author : Khushi Patel
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 31st Aug, 2024

*/


#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", (long)fileStat.st_ino);
    printf("Number of hard links: %ld\n", (long)fileStat.st_nlink);
    printf("UID: %d\n", fileStat.st_uid);
    printf("GID: %d\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", (long)fileStat.st_size);
    printf("Block size: %ld bytes\n", (long)fileStat.st_blksize);
    printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);
    printf("Time of last access: %s", ctime(&fileStat.st_atime));
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("Time of last status change: %s", ctime(&fileStat.st_ctime));

    return 0;
}




/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 9.c -o 9
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./9 f8.txt
Inode: 6836333
Number of hard links: 1
UID: 1000
GID: 1000
Size: 859 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Sat Aug 31 18:57:53 2024
Time of last modification: Sat Aug 31 18:56:25 2024
Time of last status change: Sat Aug 31 18:56:25 2024


*/
