


#include<stdio.h>

#include <sys/types.h>
#include <unistd.h>



void main()
{
    printf("gid :%d\n",getpid());
    printf("ppid:,%d\n",getppid());
}