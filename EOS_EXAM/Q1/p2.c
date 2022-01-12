//my rollnumber is 210950130017

#include <stdio.h>        
#include <fcntl.h>       
#include <sys/stat.h>    
#include <mqueue.h>
#include <string.h>

mqd_t cdacmq1;
struct mq_attr cdacmq1_attr;
unsigned char buff[64];
int msg_prio;
int c;


int main(int argc,char const *argv[])
{   
    cdacmq1_attr.mq_flags=0;       /* Flags (ignored for mq_open()) */
    cdacmq1_attr.mq_maxmsg=6;      /* Max. # of messages on queue */
    cdacmq1_attr.mq_msgsize=64;     /* Max. message size (bytes) */
    cdacmq1_attr.mq_curmsgs=0; 

    cdacmq1=mq_open("/cdacmq1", O_RDONLY,S_IRUSR | S_IWUSR,&cdacmq1_attr);
    int i=0;
    while(i<6)
    {   
        mq_receive(cdacmq1,buff,64,&msg_prio);
        
        printf("RECEIVED MESSAGE :%s\n %d\n",buff,msg_prio);
        c=strlen(buff);
        printf("LENGTH:%d\n",c);
        i++;
        
    }

    mq_unlink("/cdacmq");
    mq_close(cdacmq1);
    return 0;
    
}

