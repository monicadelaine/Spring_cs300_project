#ifndef LWS_H
#define LWS_H

#define WORD_LENGTH 100+1
#define PASSAGE_NAME_LENGTH 30+1


// Declare the message structure

typedef struct prefixbuf {
	long mtype;
  int id;
  char prefix[WORD_LENGTH];

} prefix_buf;

typedef struct foundbuf {
	long mtype;
	int index; //index of response
	int count; //total excerpts available
	int present; //0 if not found; 1 if found
	char location_description[PASSAGE_NAME_LENGTH];
	char longest_word[WORD_LENGTH];
} response_buf;
#endif
