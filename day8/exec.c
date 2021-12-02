#include<stdio.h>
#include <unistd.h>



int main(int argc,char const *argv[])
{   
    pid_t id;
    printf("BEFORE FORK\n");
    id=fork();
    printf("AFTER FORK\n");

    if(0==id)
    {
        printf("BEFORE EXEC\n");
        execl("/home/surya/git_workspace1/DAY-2-WORK/day8/out","/home/surya/git_workspace1/DAY-2-WORK/day8/out",NULL);
        printf("AFTER EXEC\n");
    }
    else
    {
        printf("PARENT\n");
    }
    printf("PROGRAM TERMINATED\n");


    return 0;
}