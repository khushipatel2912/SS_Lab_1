/*
Name : 27d.c
Author : Khushi Patel
Description :27. Write a program to execute ls -Rl by the following system calls
d. execv
Date: 31st Aug, 2024

*/




#include <stdio.h>
#include <unistd.h>

int main() {
    char *arguments[] = { "ls", "-Rl", NULL };
    printf("Executing ls -Rl using execv:\n");
    if (execv("/bin/ls", arguments) == -1) {
        perror("execv failed");
    }
    return 1;
}





/*

Output:

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ gcc 27d.c -o 27d
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./27d
Executing ls -Rl using execv:
.:
total 732
-rwxrwxr-x 1 khushi khushi 16128 Aug 31 19:08 10
-rw-rw-r-- 1 khushi khushi  1259 Aug 31 19:13 10.c
-rwxrwxr-x 1 khushi khushi 16168 Aug 31 19:17 11
-rw-rw-r-- 1 khushi khushi  1843 Aug 31 19:24 11.c
-rwxrwxr-x 1 khushi khushi 16216 Aug 31 19:26 12
-rw-rw-r-- 1 khushi khushi  1209 Aug 31 19:27 12.c
-rwxrwxr-x 1 khushi khushi 16096 Aug 31 19:29 13
-rw-rw-r-- 1 khushi khushi  1051 Aug 31 19:30 13.c
-rwxrwxr-x 1 khushi khushi 16200 Aug 31 19:32 14
-rw-rw-r-- 1 khushi khushi  1429 Aug 31 19:36 14.c
-rwxrwxr-x 1 khushi khushi 16024 Aug 31 19:38 15
-rw-rw-r-- 1 khushi khushi  3722 Aug 31 19:39 15.c
-rwxrwxr-x 1 khushi khushi 16264 Aug 31 19:45 16a
-rw-rw-r-- 1 khushi khushi   925 Aug 31 22:02 16a.c
-rwxrwxr-x 1 khushi khushi 16264 Aug 31 22:05 16b
-rw-rw-r-- 1 khushi khushi   919 Aug 31 22:05 16b.c
-rwxrwxr-x 1 khushi khushi 16112 Aug 31 22:29 17a
-rw-rw-r-- 1 khushi khushi   930 Aug 31 22:23 17a.c
-rwxrwxr-x 1 khushi khushi 16392 Aug 31 22:22 17b
-rw-rw-r-- 1 khushi khushi  1562 Aug 31 22:32 17b.c
-rwxrwxr-x 1 khushi khushi 16304 Aug 31 22:30 18a
-rw-rw-r-- 1 khushi khushi  1301 Aug 31 22:31 18a.c
-rwxrwxr-x 1 khushi khushi 16264 Aug 31 22:33 18b
-rw-rw-r-- 1 khushi khushi  1343 Aug 31 22:34 18b.c
-rwxrwxr-x 1 khushi khushi 16032 Aug 31 22:36 19
-rw-rw-r-- 1 khushi khushi   669 Aug 31 22:36 19.c
-rwxrwxr-x 1 khushi khushi 16048 Aug 31 16:01 1a
-rw-rw-r-- 1 khushi khushi   695 Aug 31 16:04 1a.c
-rwxrwxr-x 1 khushi khushi 16040 Aug 31 16:26 1b
-rw-rw-r-- 1 khushi khushi   942 Aug 31 16:58 1b.c
-rwxrwxr-x 1 khushi khushi 16040 Aug 31 17:13 1c
-rw-rw-r-- 1 khushi khushi   871 Aug 31 17:14 1c.c
-rwxrwxr-x 1 khushi khushi 15960 Aug 31 17:19 2
-rw-rw-r-- 1 khushi khushi   781 Aug 31 23:00 20.c
-rwxrwxr-x 1 khushi khushi 16088 Aug 31 23:02 21
-rw-rw-r-- 1 khushi khushi   774 Aug 31 23:02 21.c
-rwxrwxr-x 1 khushi khushi 16128 Aug 31 23:05 22
-rw-rw-r-- 1 khushi khushi   927 Aug 31 23:06 22.c
-rwxrwxr-x 1 khushi khushi 16168 Aug 31 23:07 23
-rw-rw-r-- 1 khushi khushi   600 Aug 31 23:08 23.c
-rwxrwxr-x 1 khushi khushi 16208 Aug 31 23:09 24
-rw-rw-r-- 1 khushi khushi   798 Aug 31 23:10 24.c
-rwxrwxr-x 1 khushi khushi 16136 Aug 31 23:11 25
-rw-rw-r-- 1 khushi khushi   986 Aug 31 23:12 25.c
-rwxrwxr-x 1 khushi khushi 16096 Aug 31 23:16 26
-rw-rw-r-- 1 khushi khushi   933 Aug 31 23:18 26.c
-rwxrwxr-x 1 khushi khushi 16040 Aug 31 23:22 27a
-rw-rw-r-- 1 khushi khushi  4653 Aug 31 23:23 27a.c
-rwxrwxr-x 1 khushi khushi 16048 Aug 31 23:24 27b
-rw-rw-r-- 1 khushi khushi  4885 Aug 31 23:25 27b.c
-rwxrwxr-x 1 khushi khushi 16096 Aug 31 23:25 27c
-rw-rw-r-- 1 khushi khushi  5056 Aug 31 23:26 27c.c
-rwxrwxr-x 1 khushi khushi 16096 Aug 31 23:27 27d
-rw-rw-r-- 1 khushi khushi   424 Aug 31 23:27 27d.c
-rw-rw-r-- 1 khushi khushi   179 Aug 31 23:27 27e.c
-rw-rw-r-- 1 khushi khushi  1996 Aug 31 17:28 2.c
-rw-rw-r-- 1 khushi khushi   828 Aug 31 17:37 3.c
-rw-rw-r-- 1 khushi khushi   877 Aug 31 17:44 4.c
-rw-rw-r-- 1 khushi khushi  1540 Aug 31 18:41 5.c
-rwxrwxr-x 1 khushi khushi 16096 Aug 31 18:06 6
-rw-rw-r-- 1 khushi khushi   625 Aug 31 18:08 6.c
-rwxrwxr-x 1 khushi khushi 16304 Aug 31 18:47 7
-rw-rw-r-- 1 khushi khushi  1036 Aug 31 18:52 7.c
-rwxrwxr-x 1 khushi khushi 16264 Aug 31 18:54 8
-rw-rw-r-- 1 khushi khushi  1795 Aug 31 18:58 8.c
-rwxrwxr-x 1 khushi khushi 16200 Aug 31 19:01 9
-rw-rw-r-- 1 khushi khushi  1670 Aug 31 19:02 9.c
-rwxrwxr-x 1 khushi khushi 16088 Aug 31 17:36 createfile
-rwxrwxr-x 1 khushi khushi 16128 Aug 31 18:00 createfiles
-rw-rw-r-- 1 khushi khushi    11 Aug 31 18:49 f7a.txt
-rw-rw-r-- 1 khushi khushi    11 Aug 31 18:52 f7b.txt
-rw-rw-r-- 1 khushi khushi   966 Aug 31 23:05 f8.txt
-rw-r--r-- 1 khushi khushi    31 Aug 31 23:05 f9.txt
prw-rw-r-- 1 khushi khushi     0 Aug 31 17:11 fifofile1
prw-rw-r-- 1 khushi khushi     0 Aug 31 17:13 fifofile2
-rw-r--r-- 1 khushi khushi     0 Aug 31 18:37 file1.txt
-rw-r--r-- 1 khushi khushi     0 Aug 31 18:37 file2.txt
-rw-r--r-- 1 khushi khushi     0 Aug 31 18:37 file3.txt
-rw-r--r-- 1 khushi khushi     0 Aug 31 18:37 file4.txt
-rw-r--r-- 1 khushi khushi     0 Aug 31 18:37 file5.txt
-rw-rw-r-- 1 khushi khushi    18 Aug 31 16:34 hardlink1.txt
-rw-rw-r-- 1 khushi khushi     0 Aug 31 17:56 hardlink.txt
-rwxrwxr-x 1 khushi khushi 16088 Aug 31 17:43 openfile
-rw-rw-r-- 1 khushi khushi     0 Aug 21 23:11 README.md
-rw-r--r-- 1 khushi khushi    30 Aug 31 19:12 seektest.txt
lrwxrwxrwx 1 khushi khushi     6 Aug 31 13:06 symlink1 -> f1.txt
lrwxrwxrwx 1 khushi khushi    28 Aug 31 16:01 symlink1a -> /home/khushi/my-repo/f1a.txt
-rw-r--r-- 1 khushi khushi     5 Aug 31 22:22 tkt.txt


*/
