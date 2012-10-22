/*
 * machina.h
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */

#ifndef MACHINA_H_
#define MACHINA_H_
#include "message.h"
#include "target.h"
#include "callback.h"
#include "parser.h"
extern int Request(Message* msg,Target* target);
extern int RegirstTarget(Target* target);
extern int SetCallBack(CallBack cb);
extern int SetParser(Parser parser);
extern int Block();

#endif /* MACHINA_H_ */
