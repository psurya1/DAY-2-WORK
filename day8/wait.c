#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char const *argv[])
{
   

   pid_t id;
   int n;
   id =fork();
   if(id ==0)
   {   
     n=1;
   }
   else
   {
     n=6;
   }
   if(id!=0)
   {
     wait();
   }
 
   for(int i=n;i<n+5;i++)
   {
     printf("%d",i);
   }
   printf("\n");
   return 0;




}