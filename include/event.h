/*
 * asyncevent.h
 *
 *  Created on: 2012-11-5
 *      Author: jl
 */

#ifndef EVENT_H_
#define EVENT_H_
#include "target.h"
#include "message.h"
typedef enum __eventType{
	CONNECT_EVENT,
	ACCEPT_EVENT,
	DISCONNECT_EVENT,
	WRITE_EVENT,
	READ_EVENT
}EventType;

typedef enum __StatusType{
	INIT_STAT,
	SUCCESS_STAT,
	FAIL_STAT
}StatusType;

typedef struct __tagEvent{
	EventType eventId;
	int	status;
	PTarget target;
	PMessage message;
}Event,*PEvent;

int PostAsyncEvent(PEvent event);
typedef void (*EventCB)(PEvent event);
int SetEventCompleteCB(EventCB cb);
int DoEvent();
PEvent AllocEvent(EventType);
void FreeEvent(PEvent);

#endif /* EVENT_H_ */
