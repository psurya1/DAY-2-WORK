#include <stdio.h>
#include <unistd.h>
#include <string.h>


/* what ever command(/bin/) given in DSEDSHELL it will loaded in child address space 
   through exec */
int main(int argc,char const *argv[])
{   
    pid_t id;
    int fd[2];
    unsigned char cmd[20];

    printf("DSEDSHELL $");
    scanf("%s",cmd);

    unsigned char buff1[20];
    unsigned char buff2[20];
    strcpy(buff1,cmd);
    pipe(fd);
    id=fork();
    if(0==id)
    {   
        unsigned char path[5]="/bin/";  
        read(fd[0],&buff2,20);    // child is receiving command
    //  printf("%s",buff2);
        printf("CHILD\n");
        execl(path,buff2,NULL);   // child is loaded with new program through exec
    
    }
    else
    {
        printf("PARENT\n");        // parent is passing command through pipe
        
        write(fd[1],&buff1,20);
    }
    


    return 0;
}