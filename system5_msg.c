#include "edu_cs300_MessageJNI.h"
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <jni.h>
#include "longest_word_search.h"
#include "queue_ids.h"


#ifndef mac
size_t                  /* O - Length of string */
strlcpy(char       *dst,        /* O - Destination string */
        const char *src,      /* I - Source string */
        size_t      size)     /* I - Size of destination string buffer */
{
    size_t    srclen;         /* Length of source string */


    /*
     * Figure out how much room is needed...
     */

    size --;

    srclen = strlen(src);

    /*
     * Copy the appropriate amount...
     */

    if (srclen > size)
        srclen = size;

    memcpy(dst, src, srclen);
    dst[srclen] = '\0';

    return (srclen);
}

#endif


JNIEXPORT jstring JNICALL Java_edu_cs300_MessageJNI_readStringMsg
(JNIEnv *env, jobject obj) {

    key_t key;
    int msqid;
    prefix_buf rbuf;
    int msgflg = IPC_CREAT | 0666;

    // ftok to generate unique key
    key = ftok(CRIMSON_ID, QUEUE_NUMBER);

    // msgget creates a message queue
    // and returns identifier
    if ((msqid = msgget(key, msgflg)) < 0) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("(msgget)");
        fprintf(stderr, "Error msgget: %s\n", strerror( errnum ));
    }
    else
        fprintf(stderr, "msgget: msgget succeeded: msgqid = %d\n", msqid);

    // msgrcv to receive message
    int ret = msgrcv(msqid, &rbuf, WORD_LENGTH, 1, 0);//TODO what is the correct length here
    if (ret < 0) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Error receiving msg: %s\n", strerror( errnum ));
        strcpy(rbuf.prefix,"error");//return error to java program
    }

    jstring result;

    puts(rbuf.prefix);
    result = (*env)->NewStringUTF(env,rbuf.prefix);
    return result;
}


/*
 * Class:     edu_cs300_MessageJNI
 * Method:    readPrefixRequestMsg
 * Signature: (Ljava/lang/String;I)Ledu/cs300/SearchRequest;
 */
JNIEXPORT jobject JNICALL Java_edu_cs300_MessageJNI_readPrefixRequestMsg
(JNIEnv *env, jobject obj) {


    key_t key;
    int msqid;
    prefix_buf rbuf;


    // ftok to generate unique key
    //key = ftok(CRIMSON_ID, QUEUE_NUMBER);
    key = ftok(CRIMSON_ID, QUEUE_NUMBER);

    // msgget creates a message queue
    // and returns identifier
    msqid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message
    int ret = msgrcv(msqid, &rbuf, WORD_LENGTH, 1, 0);//TODO what is the correct length here
    if (ret < 0) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Error receiving msg: %s\n", strerror( errnum ));
        strcpy(rbuf.prefix,"error");//return error string to calling program
    }
    fprintf(stderr,"id=%d prefix=%s\n", rbuf.id,rbuf.prefix);

    // Create the object of the class UserData
    jclass searchRequestClass = (*env)->FindClass(env,"edu/cs300/SearchRequest");
    jobject searchRequest = (*env)->AllocObject(env,searchRequestClass);

    // Get the UserData fields to be set
    jfieldID prefixField = (*env)->GetFieldID(env,searchRequestClass , "prefix", "Ljava/lang/String;");
    jfieldID idField = (*env)->GetFieldID(env,searchRequestClass , "requestID", "I");

    jstring result = (*env)->NewStringUTF(env,rbuf.prefix);

    (*env)->SetObjectField(env,searchRequest, prefixField, result);
    (*env)->SetIntField(env,searchRequest, idField, rbuf.id);
    return searchRequest;

}

/*
 * Class:     edu_cs300_MessageJNI
 * Method:    writeLongestWordResponseMsg
 * Signature: (Ljava/lang/String;IILjava/lang/String;ILjava/lang/String;Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_edu_cs300_MessageJNI_writeLongestWordResponseMsg
(JNIEnv *env , jobject obj, jint prefixID, jstring prefixStr, jint passageIndex, jstring passageNameStr, jstring longestWordStr, jint passageCount, jint present) {


    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    response_buf rbuf;

    key = ftok(CRIMSON_ID,QUEUE_NUMBER);
    if ((msqid = msgget(key, msgflg)) < 0) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("(msgget)");
        fprintf(stderr, "Error sending msg: %s\n", strerror( errnum ));
    }
    else
        fprintf(stderr, "msgget: msgget succeeded: msgqid = %d\n", msqid);

    const char *prefix = (*env)->GetStringUTFChars(env,prefixStr, NULL);
    const char *passageName = (*env)->GetStringUTFChars(env,passageNameStr, NULL);
    const char *longestWord = (*env)->GetStringUTFChars(env,longestWordStr, NULL);
    int psl = strlen(passageName);
    int lwl=strlen(longestWord);
    int buffer_length=sizeof(response_buf)-sizeof(long); //int

    printf("msgsnd Reply %d of %d on %d:%s from %s present=%d lw=%s(len=%d) msglen=%d\n",passageIndex,passageCount,prefixID,prefix,passageName,present,longestWord,lwl,buffer_length);

    // // We'll send message type 1
    rbuf.mtype = 2;
    rbuf.index=passageIndex; //index of response
    rbuf.count=passageCount; //total excerpts available
    rbuf.present=present; //0 if not found; 1 if found


    if (present ==0) {
        strlcpy(rbuf.location_description,passageName,PASSAGE_NAME_LENGTH);
        strlcpy(rbuf.longest_word,"--",2);
    } else {
        strlcpy(rbuf.location_description,passageName,PASSAGE_NAME_LENGTH);
        strlcpy(rbuf.longest_word,longestWord,WORD_LENGTH);
    }
    //
    // Send a message.
    if((msgsnd(msqid, &rbuf, buffer_length, IPC_NOWAIT)) < 0) {
        int errnum = errno;

        perror("(msgsnd)");
        fprintf(stderr, "Error sending msg: %s\n", strerror( errnum ));
        exit(1);
    }
    else
        fprintf(stderr,"Message: \"%d:%s\" Sent\n",rbuf.index, rbuf.longest_word);


    (*env)->ReleaseStringUTFChars(env, prefixStr, prefix);
    (*env)->ReleaseStringUTFChars(env, passageNameStr, passageName);
    (*env)->ReleaseStringUTFChars(env, longestWordStr, longestWord);

}


