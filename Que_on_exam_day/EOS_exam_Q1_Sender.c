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
#include<string.h>
#include <stdlib.h> 
#include <unistd.h> 

//mqd_t dictionary.txt;
int main()
{
    int fd_one;
    int fd_two;
    char buff;

    fd_one = open("dictionary.txt", O_RDONLY); 
    
    if (fd_one== -1) 
     { printf("Error opening first_file\n"); 
     close(fd_one); 

    fd_open = open("dictionary.txt", O_RDONLY); 
    
    if (fd== -1) 
     { printf("Error opening first_file\n"); 
     close(fd); 

     
      } 
      else
      {
          printf ("Sucessfully open\n");
      }
       fd_two = open("Dest.txt", O_WRONLY);  
      while(read(fd_one, &buff, 1)) 
      { 
          write(fd_two, &buff, 1); 
          } 
          printf("Successful copy"); 
         

          close(fd_one); 
          close(fd_two); 

          
while(read(fd_one, &buff, 1)) 
{
    if (buff ==  'm');
    {
        printf ("msg = %s\n", buff);
    }
}
mqd_t cdacmq = buff;
struct mq_attr cdacmq_attr;



    cdacmq_attr.mq_flags =0;           // flags for msg, ignored in case of open
    cdacmq_attr.mq_maxmsg =1;          // how many msg you want to send
    cdacmq_attr.mq_msgsize =128;       // msx size of msg in bytes
    cdacmq_attr.mq_curmsgs = 0;        // current msg in queue, 0 for the first time
    
    cdacmq = mq_open ("/cdacmq", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);
    //mqd_t cdacmq;
    return 0;
}



