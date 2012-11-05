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
 * ����һ������
 * @param msg Ҫ������Ϣ
 * @param target �����Ŀ��
 */
extern int Request(Message* msg,Target* target);
/*
 * �������ע��Ŀ��
 * @param target Ŀ����Ϣ
 * @see target->protocol
 */
extern int RegirstTarget(Target* target);
/*
 * �豸�ص�ָ��
 * @param cb �ص�������ָ��
 */
extern int SetCallBack(CallBack cb);
/*
 * �豸���ݰ�������
 * @param parser ������������ָ��
 */
extern int SetParser(Parser parser);
/*
 * ������������ʼ������Ϣ���˺�������
 */
extern int TurnOn();
/*
 * �رջ���
 */
extern int Poweroff();

#endif /* MACHINA_H_ */
