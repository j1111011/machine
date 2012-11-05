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
/*
 * 发出一个请求
 * @param msg 要发出消息
 * @param target 发向的目标
 */
extern int Request(Message* msg,Target* target);
/*
 * 向机器中注册目标
 * @param target 目标信息
 * @see target->protocol
 */
extern int RegirstTarget(Target* target);
/*
 * 设备回调指针
 * @param cb 回调函数集指针
 */
extern int SetCallBack(CallBack cb);
/*
 * 设备数据包解析器
 * @param parser 解析器处理函数指针
 */
extern int SetParser(Parser parser);
/*
 * 开启机器，开始处理消息，此函数阻塞
 */
extern int TurnOn();
/*
 * 关闭机器
 */
extern int Poweroff();

#endif /* MACHINA_H_ */
