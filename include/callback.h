/*
 * callback.h
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */

#ifndef CALLBACK_H_
#define CALLBACK_H_
#include "target.h"
typedef struct __tagCallBack{
	void (*OnRespond)(Message* msg,Target* target);
	void (*OnErrorOccur)(int err,Target* target);
	void (*OnTargetRegirsted)(Target* target);
	void (*OnTargetUnRegirsted)(const Target* target);
}CallBack;
#endif /* CALLBACK_H_ */
