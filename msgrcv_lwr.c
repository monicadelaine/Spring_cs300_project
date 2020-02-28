#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "longest_word_search.h"
#include "queue_ids.h"

int main(int argc, char**argv)
{
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    response_buf rbuf;
    size_t buf_length;

    key = ftok(CRIMSON_ID,QUEUE_NUMBER);
    if ((msqid = msgget(key, msgflg)) < 0) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("(msgget)");
        fprintf(stderr, "Error msgget: %s\n", strerror( errnum ));
    }
    else
        fprintf(stderr, "msgget: msgget succeeded: msgqid = %d\n", msqid);


    // msgrcv to receive message
    int ret;
    do {
      ret = msgrcv(msqid, &rbuf, sizeof(response_buf), 2, 0);//receive type 2 message
      int errnum = errno;
      if (ret < 0 && errno !=EINTR){
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Error receiving msg: %s\n", strerror( errnum ));
      }
    } while ((ret < 0 ) && (errno == 4));
    //fprintf(stderr,"msgrcv error return code --%d:$d--",ret,errno);

    if (rbuf.present == 1)
        fprintf(stderr,"%ld, %d of %d, %s, size=%d\n", rbuf.mtype, rbuf.index,rbuf.count,rbuf.longest_word, ret);
    else
        fprintf(stderr,"%ld, %d of %d, not found, size=%d\n", rbuf.mtype, rbuf.index,rbuf.count, ret);

    exit(0);
}
