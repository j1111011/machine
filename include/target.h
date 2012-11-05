/*
 * target.h
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */

#ifndef TARGET_H_
#define TARGET_H_
#define SOCKET_PROTOCOL 0
#define SOCKET_SELF 1
typedef struct __tagTarget{
	char protocol;
	char address[128];
	unsigned short port;
	int	fd;
}Target,*PTarget;

void CopyTarget(PTarget dest,PTarget src);

#endif /* TARGET_H_ */
