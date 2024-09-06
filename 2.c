/*
Name : 2.c
Author : Khushi Patel
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 31st Aug, 2024.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {
	  printf("Infinite loop...\n");	
        }
    return 0;
}


/* Output: 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ ./infiniteloop &
[1] 2370
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo$ cat /proc/2370/status

Name:	infiniteloop
Umask:	0002
State:	R (running)
Tgid:	2370
Ngid:	0
Pid:	2370
ppPPid:	2351
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	64
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	2370
NSpid:	2370
NSpgid:	2370
NSsid:	2370
VmPeak:	   27408 kB
VmSize:	   26356 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	   12800 kB
VmRSS:	   12800 kB
RssAnon:	    5376 kB
RssFile:	    7424 kB
RssShmem:	       0 kB
VmData:	    5824 kB
VmStk:	     132 kB
VmExe:	    2936 kB
VmLib:	    6108 kB
VmPTE:	      88 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	2
SigQ:	1/62707
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000003000
SigCgt:	000000016f8a4eff
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	980
nonvoluntary_ctxt_switches:	18
*/
