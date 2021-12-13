#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include<stdio.h>
#include<mqueue.h>



mqd_t cdacmq;
struct mq_attr cdacmq_attr;
unsigned char buff[64];
int msg_prio;



int main(int argc,char const *argv[])
{   
    cdacmq_attr.mq_flags=0 ;     /* Flags (ignored for mq_open()) */
    cdacmq_attr.mq_maxmsg=4 ;     /* Max. # of messages on queue */
    cdacmq_attr.mq_msgsize=64;     /* Max. message size (bytes) */
    cdacmq_attr.mq_curmsgs=0;

    cdacmq=mq_open("/cdacmq",O_RDONLY | O_CREAT,S_IRUSR | S_IWUSR,&cdacmq_attr);

    mq_receive(cdacmq,buff,64,&msg_prio);
    printf("RECEIVED MESSAGE :%s\n %d",buff,msg_prio);
    mq_close(cdacmq);
    return 0;
}