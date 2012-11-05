/*
 * message.c
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */
#include "message.h"
extern Message* AllocMessage(size_t len){
	Message* msg = (Message*)malloc(sizeof(Message));
	msg->len = len;
	msg->buffer = (char*)malloc(len);
	return	msg;
}
extern void DestoryMessage(Message* msg){
	free(msg->buffer);
	free(msg);
}

extern void CopyMessage(PMessage dst,PMessage src){
	if(dst->len >= src->len){
		dst->len = src->len;
		memcpy(dst->buffer,src->buffer,src->len);
	}
	else {
		free(dst->buffer);
		dst->buffer = (char*)malloc(src->len);
		dst->len = src->len;
		memcpy(dst->buffer,src->buffer,src->len);
	}
}
