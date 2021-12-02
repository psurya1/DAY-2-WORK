#include<stdio.h>
#include <pthread.h>



void *greet_thread(void *arg)
{
    printf("%s thread\n",arg);

}


int main(int argc,char const *argv[])
{   
    pthread_t helloID,byeid;
    printf("BEFORE THREAD\n");
    pthread_create(&helloID,NULL,greet_thread,"hello");
    pthread_create(&byeid,NULL,greet_thread,"bye");
    pthread_join(helloID,NULL);
    pthread_join(byeid,NULL);
    printf("AFTER THREAD\n");
    return 0;
}