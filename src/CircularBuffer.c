/*
 * CircularBuffer.c
 *
 *  Created on: Mar 29, 2019
 *      Author: atbecker22
 */
#include "CircularBuffer.h"

//Initializes the struct commBuffer_t to zero, Type = Rx or Tx
void initBuffer(commBuffer_t* comm, uint8_t type){
	comm->MessageCount = 0;
	comm->bufferSize = 0;
	comm->head = 0;
	comm->tail = 0;
	comm->type = type;
	memset(comm->buffer, '~', MAXCOMMBUFFER+1);
}
//Test if a complete message is in buffer delimiter is \n
uint8_t haveMessage(commBuffer_t* comm){
	if(comm->MessageCount){
		return 1;
	}
	else{
		return 0;
	}
}
//Put character in buffer and update head
void putChar(commBuffer_t* comm, char ch){
	comm->buffer[comm->head] = ch;
	comm->head++;
	if(comm->head == MAXCOMMBUFFER){
		comm->head = 0;
	}
	if(ch == '\n'){
		comm->MessageCount++;
	}
}
//Get character from buffer and update tail;
char getChar(commBuffer_t* comm){
	int i = comm->tail;
	comm->tail++;
	if(comm->tail == MAXCOMMBUFFER){
		comm->tail = 0;
	}
	return comm->buffer[i];
}
//put C string into buffer
void putMessage(commBuffer_t* comm, char* str, uint8_t length){
	for(int ndx = 0; ndx < length; ndx++){
		putChar(comm, str[ndx]);
	}
}
//get C string from buffer
void getMessage(commBuffer_t* comm, char* str){
	int ndx = 0;
	while(comm->head != comm->tail){
		str[ndx] = getChar(comm);
		if(ndx == 0 && str[ndx] == '\n'){
			comm->tail = comm->head;
			str[ndx] = ' ';
			ndx++;
			str[ndx] = '\n';
		}
		ndx++;
	}
	str[ndx] = '\0';
	comm->head++;
	comm->tail++;

	comm->MessageCount -= 1;
}
//get Size of Buffer
int getBufferSize(commBuffer_t* comm){
	return (comm->head - comm->tail + MAXCOMMBUFFER)%MAXCOMMBUFFER;
}
