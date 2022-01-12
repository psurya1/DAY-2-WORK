
//my rollnumber is 210950130017

#include <stdio.h>        
#include <fcntl.h>       
#include <sys/stat.h>    
#include <mqueue.h>
#include <string.h>

mqd_t cdacmq1;
struct mq_attr cdacmq1_attr;



int main(int argc,char const *argv[])
{   
    cdacmq1_attr.mq_flags=0;       /* Flags (ignored for mq_open()) */
    cdacmq1_attr.mq_maxmsg=6;      /* Max. # of messages on queue */
    cdacmq1_attr.mq_msgsize=64;     /* Max. message size (bytes) */
    cdacmq1_attr.mq_curmsgs=0; 

    cdacmq1=mq_open("/cdacmq1", O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR,&cdacmq1_attr);

    char buff[60];
    FILE *fp;
    fp=fopen("dictionary.txt","r");
    if(fp==NULL)
    {
        printf("ERROR IN READING\n");
    }
    char str[60];
    int i=0;
    while((fgets(str,60,fp)!=NULL) && i<6)
    {
        if((str[0])=='m' || str[0]=='M')
        {
            strcpy(buff,str);
            mq_send(cdacmq1,buff,7,0);
            i++;
        }
    }
 
        
    mq_close(cdacmq1);
    

    return 0;
}

