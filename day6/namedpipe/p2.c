#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc,char const *argv[])
{   
   
    int fd;
    unsigned char buff[fd];

    fd=open("desdfifo",O_RDONLY);
    read(fd,buff,sizeof(buff));
    printf("RESULT :%s\n",buff);
    close(fd);

    return 0;
}