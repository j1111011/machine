/*
 * machine.cpp
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */
#include "machine.h"
#include "event.h"

CallBack gMachineCB = {NULL,NULL,NULL,NULL};
Parser gMachineParser = {NULL,NULL};
int _networkReqeust(Message*msg,Target* target) {
	PEvent e = AllocEvent(WRITE_EVENT);
	CopyMessage(e->message,msg);
	CopyTarget(e->target,target);
	return	PostAsyncEvent(e);
}
extern int Request(Message* msg, Target* target) {
	if(target->protocol == SOCKET_PROTOCOL){
		return	_networkReqeust(msg,target);
	}
	return	-1;
}

int _registNetWorkTarget(Target* target) {
	if(target->protocol == SOCKET_PROTOCOL){
		PEvent e = AllocEvent(CONNECT_EVENT);
		CopyTarget(e->target,target);
		PostAsyncEvent(e);
	}
	else if(target->protocol == SOCKET_SELF){
		PEvent e = AllocEvent(ACCEPT_EVENT);
		CopyTarget(e->target,target);
		PostAsyncEvent(e);
	}
	return	0;
}

extern int RegirstTarget(Target* target) {
	if(target->protocol == SOCKET_PROTOCOL ||
			target->protocol == SOCKET_SELF){
		return	_registNetWorkTarget(target);
	}
	return -1;
}

extern int SetCallBack(CallBack cb) {
	gMachineCB = cb;
	return 0;
}

extern int SetParser(Parser parser) {
	gMachineParser = parser;
	return	0;
}

void __eventCallBack(PEvent e){
	int err = 0;
	int err_code = 1;
	if(e->eventId == CONNECT_EVENT){
		if(e->status == SUCCESS_STAT){
			gMachineCB.OnTargetRegirsted(e->target);
		}
	}
	if(e->eventId == ACCEPT_EVENT){
		if(e->status == SUCCESS_STAT){
			gMachineCB.OnTargetRegirsted(e->target);
		}
	}
	if(e->eventId == DISCONNECT_EVENT){
		if(e->status == SUCCESS_STAT){
			gMachineCB.OnTargetUnRegirsted(e->target);
		}
	}
	else if(e->eventId == WRITE_EVENT){
		if(e->status == FAIL_STAT){

		}
	}
	else if(e->eventId == READ_EVENT){
		if(e->status == SUCCESS_STAT){
			gMachineCB.OnRespond(e->message,e->target);
		}
	}
	if(err == 1){
		gMachineCB.OnErrorOccur(err_code,e->target);
	}
}
extern int TurnOn() {
	SetEventCompleteCB(__eventCallBack);
	return	DoEvent();
}

extern int Poweroff(){
	return	0;
}
