#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>



int main(int argc,char const *argv[])
{
    int fd[2];
    char buff[15];
    
    fd[0]=open(argv[1], O_RDONLY);
    fd[1]=open(argv[2], O_WRONLY);

    if(fd[0]==-1 | fd[1]==-1)
    {
        perror("ERROR IN OPENING");
        exit(EXIT_FAILURE);
    }
    else
    {
        read(fd[0],buff,sizeof(buff));
        write(fd[1],buff,sizeof(buff));
        

    }
      
     
    
    
    close(fd[0]);
    close(fd[1]);
    return 0;
}
