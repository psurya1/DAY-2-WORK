#include <stdio.h>
#include <pthread.h>

int count = 10;
pthread_mutex_t mutexcount;
pthread_mutexattr_t mutexattrcount;
void *inc_thread(void *arg)
{
    while (1)
    {   
        pthread_mutex_lock(&mutexcount);
        count++;
        printf("INC_COUNT :%d\n", count);
        pthread_mutex_unlock(&mutexcount);
    }
}
void *dec_thread(void *arg)
{
    while(1)
    {   
        pthread_mutex_lock(&mutexcount);
        count--;
        printf("DEC_COUNT :%d\n",count);
        pthread_mutex_unlock(&mutexcount);
    }
}

int main(int argc, char const *argv[])

{
    pthread_t incID, decID;
    pthread_mutexattr_init(&mutexattrcount);
    pthread_mutexattr_settype(&mutexattrcount, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutexcount,&mutexattrcount);
    pthread_create(&incID, NULL, inc_thread, NULL);
    pthread_create(&decID, NULL, dec_thread, NULL);
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);
    pthread_mutex_destroy(&mutexcount);
    return 0;
}