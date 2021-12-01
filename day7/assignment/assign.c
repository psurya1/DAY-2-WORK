#include <stdio.h>
#include <pthread.h>


void *hello_thread(void * arg)
{
    printf("HELLO THREAD\n");
}
void *bye_thread(void * arg)
{
    printf("BYE THREAD\n");
}




int main(int argc,char const *argv[])
{
    pthread_t helloID,byeID;
    printf("MAIN THREAD : before creating hello thread\n");

    pthread_create(&helloID,NULL,hello_thread,NULL);
    pthread_create(&byeID,NULL,bye_thread,NULL);
    pthread_join(helloID,NULL);
    pthread_join(byeID,NULL);
    
    printf("MAIN THREAD : after creating hello thread\n");

    return 0;
}