#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


void main(int argc,char const *argv[])
{
    int fd;
    fd=open("desd.txt",O_WRONLY | O_CREAT);
    
    if(fd==-1)
    {
        perror("ERROR:%d\n");
        exit(EXIT_FAILURE);
    
    }
    write(fd,"DSED STUDENT",sizeof("DSED STUDENT"));
    close(fd);
    return 0;
}