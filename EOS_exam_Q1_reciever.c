// Name - KAJOL
// PRN - 210950130009
// exam question - Q1
//========================//
// Open the file /usr/share/dictionary.txt in process P1 and 
// send the strings starting with letter 'm' to process P2 using message queues. 
// In process P2 find and print the length of string.  

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t cdacmq;

struct mq_attr cdacmq_attr;

char buff[128];
int msg_prio;

int main (int argc, char const *argv[])
{
    cdacmq_attr.mq_flags =0;
    cdacmq_attr.mq_maxmsg =4;
    cdacmq_attr.mq_msgsize =128;
    cdacmq_attr.mq_curmsgs = 0;

//  mqd_t  = mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);

    cdacmq = mq_open ("/cdacmq", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);

// ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);

    mq_receive(cdacmq, buff, 128, &msg_prio);

    printf ("Recieved msg: %s\nMsg prio : %d\n", buff, msg_prio );

    mq_close(cdacmq);

    return 0;
}
