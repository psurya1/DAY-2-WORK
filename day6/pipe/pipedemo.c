#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>




int main(int argc,char const *argv[])
{
  unsigned char buff[15],buss[10];
  pid_t id;
  int fd[2],fp[2];
  pipe(fd);
  pipe(fp);



  id =fork();
  if(id ==0)
  {  
     printf("CHILD : READING DATA\n");
     read(fd[0],buff,sizeof(buff)); // child is writing
     printf("CHILD READ :%s\n",buff);
     write(fp[1],"HELLO\n",6);      // child is writing
     printf("CHILD : WRITING IS DONE\n");
     
  }
  else
  {
     printf("PARENT :WRITING DATA\n");
     write(fd[1],"DSED\n",5);       // parent is writing
     printf("PARENT : WRITING IS DONE\n");
     read(fp[0],buss,sizeof(buss)); // parent is reading
     printf("PARENT READ: %s\n",buss);

  }

  return 0;
}