#include<stdio.h>
#include <unistd.h>




int main(int argc,char const *argv[])
{   
    pid_t id;
    int fd[2],fp[2];
    //int val1=0,val2=0;
    int arr[2];
    int sum=0;
    int b1,b2,b3;
    pipe(fd);
    pipe(fp);

    id =fork();


    if(id ==0)
    {
        printf("1: CHILD READING\n");
        
        read(fd[0],&b1,sizeof(b1));  
        read(fd[0],&b2,sizeof(b2));
        
        sum=(b1 + b2);
        printf("2: CHILD WRITING\n");
        write(fp[1],&sum,sizeof(sum));  // result is transmitted to parent


    }
    else
    {
        printf("1: PARENT WRITING\n");
        // val1=20; 
        arr[0]=10;                     //here i am sending value 20
        //  write(fd[1],&val1,sizeof(val1));
        // val2=30; 
        arr[1]=20;                     // here i am sending value 30
        write(fd[1],arr,sizeof(arr));
        printf("2: PARENT READING\n");
        read(fp[0],&b3,sizeof(b3));    // result is received from child
        printf("RESULT: %d\n",b3);

    }


    return 0;
}