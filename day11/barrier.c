#include<stdio.h>
#include<pthread.h>

pthread_barrier_t b1;

void *temp_thread(void *arg)
{
    printf("TEMP STARTS INIT\n");
  //  sleep(2);
    pthread_barrier_wait(&b1);
    printf("TEMP COMPLETED\n");
}
void *ethernet_thread(void *arg)
{
    printf("ETHERNET STARTS INIT\n");
   // sleep(3);
    pthread_barrier_wait(&b1);
    printf("ETHERNET COMPLETED\n");
}
void *i2c_thread(void *arg)
{
    printf("I2C STARTS INIT\n");
  //  sleep(1);
    pthread_barrier_wait(&b1);
    printf("I2C COMPLETED\n");
}
void *uart_thread(void *arg)
{
    printf("UART STARTS INIT\n");
   // sleep(3);
    pthread_barrier_wait(&b1);
    printf("UART COMPLETED\n");
}

int main(int argc,char const *argv[])
{   
    pthread_t temp,ethernet,i2c,uart;

    pthread_barrier_init(&b1,NULL,4);

    pthread_create(&temp,NULL,temp_thread,NULL);
    pthread_create(&ethernet,NULL,ethernet_thread,NULL);
    pthread_create(&i2c,NULL,i2c_thread,NULL);
    pthread_create(&uart,NULL,uart_thread,NULL);
    pthread_join(temp,NULL);
    pthread_join(ethernet,NULL);
    pthread_join(i2c,NULL);
    pthread_join(uart,NULL);
    return 0;
}