/*
 * message.h
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <stdlib.h>
typedef struct __tagMsg{
	size_t len;
	char* buffer;
}Message,*PMessage;

extern Message* AllocMessage(size_t len);
extern void DestoryMessage(Message* msg);
extern void CopyMessage(PMessage dst,PMessage src);
#endif /* MESSAGE_H_ */
