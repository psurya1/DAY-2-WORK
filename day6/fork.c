#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>




int main(int argc,char const *argv[])
{
   

   pid_t id;
   printf("BEFORE FORK\n");
   id =fork();
   if(id ==0)
   {
       printf("CHILD : PID %d\n",getpid());
       printf("CHILD : PPID %d\n",getppid());
   }
   else{
       printf("PARENT : PID %d\n",getpid());
       printf("PARENT : PPID %d\n",getppid());
       sleep(5);
       printf("PARENT DONE\n");
   }

   return 0;




}