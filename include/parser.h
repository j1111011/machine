/*
 * parser.h
 *
 *  Created on: 2012-10-22
 *      Author: jl
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdlib.h>
#include "message.h"
typedef struct __tagParser{
	int (*Push)(const char* data,size_t len);
	void (*Pull)(Message* msg,size_t max);
}Parser;
#endif /* PARSER_H_ */
