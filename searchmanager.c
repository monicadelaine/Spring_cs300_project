//AUTHOR: Sarah Liang
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "longest_word_search.h"
#include "queue_ids.h"

#ifdef DEBUG = 1; //set to 0 if not debug

int main(int argc, char **argv){
    //set up SIGINT


    //how long between each request, for testing
    int waitSecs = atoi(argv[0]);

    //send messages

    

}

void sendMsg(char *prefix){
     int msqid;
     msqid = msgget(key, msgflg);
     prefix_buf sbuf;
     size_t buf_length;

     //debug for getting qid
     if (DEBUG  && msqid < 0) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("(msgget)");
        fprintf(stderr, "Error msgget: %s\n", strerror( errnum ));
    }

    //add to buffer
    sbuf.mtype = 1;
    strcpy(sbuf.prefix, prefix); //copy prefix into buffer
    sbuf.id=0; //FIXME what is id
    buf_length = strlen(sbuf.prefix) + sizeof(int)+1;//struct size without long int type

    msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT)

}


