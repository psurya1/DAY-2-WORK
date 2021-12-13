#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>     
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

int *count;
int num;
sem_t s1;

int main(int argc,char const *srgv[])
{ 

    int shmd;
    sem_init(&s1,1,1);
    shmd=shm_open("/cdac",O_RDWR | O_CREAT,S_IRUSR | S_IWUSR);
    ftruncate(shmd,sizeof(int));
    count=(int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);
    while(1)
    {   
        sem_wait(&s1);
        scanf("%d",&num);
        *count=num;
        sem_post(&s1);
    }
    sem_destroy(&s1);
    shmd=shm_unlink("/cdac");
    return 0;
}