/*
 * event.c
 *
 *  Created on: 2012-11-5
 *      Author: jl
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "event.h"
#include "queue.h"
pqueue que;
pqueuenode eventQueue;
EventCB gEventCB;
int gStopFlags = 0;
int PostAsyncEvent(PEvent event){
	queueelem elem;
	elem.value = (int)event;
	que->push(eventQueue,&elem);
	return	0;
}
int SetEventCompleteCB(EventCB cb){
	gEventCB = cb;
	return	0;
}
void __processEvent(PEvent e){
	if(e->eventId == CONNECT_EVENT){
		e->target->fd = socket(AF_INET,SOCK_STREAM,0);
		struct sockaddr_in addr;
		memset(&addr,0,sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(e->target->address);
		addr.sin_port = htons(e->target->port);
		if(0 == connect(e->target->fd,(struct sockaddr*)&addr,sizeof(addr))){
			e->status = SUCCESS_STAT;
		}
		else {
			e->status = FAIL_STAT;
		}
	}
	else if(e->eventId == WRITE_EVENT){
		if(e->message->len == write(e->target->fd,e->message->buffer,e->message->len)){
			e->status = SUCCESS_STAT;
		}
		else {
			e->status = FAIL_STAT;
		}
	}
	else if(e->eventId == READ_EVENT){
		size_t rds = read(e->target->fd,e->message->buffer,e->message->len);
		if(rds > 0){
			e->status = SUCCESS_STAT;
		}
		else {
			e->status = FAIL_STAT;
		}
		e->message->len = rds;
	}
	gEventCB(e);
}
int DoEvent(){
	gStopFlags = 0;
	que = new_queue();
	eventQueue = que->create();
	/// ...
	while(!gStopFlags){
		if(que->empty(eventQueue)){
			sleep(1);
			continue;
		}
		pqueueelem pelem = que->front(eventQueue);
		if(pelem){
			PEvent e = (PEvent)pelem->value;
			__processEvent(e);
		}
		que->pop(eventQueue);
	}
	que->destory(eventQueue);
	delete_queue(que);
	return	0;
}
PEvent AllocEvent(EventType type){
	PEvent e = (PEvent)malloc(sizeof(Event));
	e->eventId = type;
	e->status = INIT_STAT;
	return	e;
}
void FreeEvent(PEvent e){
	free(e);
}
