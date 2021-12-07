#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a,b;
int sum;
sem_t s1,s2;

void *input_thread(void *arg)
{
    while(1)
    {   
        sem_wait(&s1);
        scanf("%d",&a);
        scanf("%d",&b);
        sem_post(&s2);
    }
}
void *proc_thread(void *arg)
{
    while(1)
    {   
        sem_wait(&s2);
        sum=a+b;
        printf("SUM:%d",a+b);
        sem_post(&s1);
    }
}


int main(int argc,char const *argv[])
{   
    pthread_t inputid,procid;
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    pthread_create(&inputid,NULL,input_thread,NULL);
    pthread_create(&procid,NULL,proc_thread,NULL);
    pthread_join(inputid,NULL);
    pthread_join(procid,NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}
