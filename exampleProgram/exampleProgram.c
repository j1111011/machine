/*
 ============================================================================
 Name        : exampleProgram.c
 Author      : JL
 Version     :
 Copyright   : JL FSF
 Description : Uses shared library to print greeting
               To run the resulting executable the LD_LIBRARY_PATH must be
               set to ${project_loc}/libmachine/.libs
               Alternatively, libtool creates a wrapper shell script in the
               build directory of this program which can be used to run it.
               Here the script will be called exampleProgram.
 ============================================================================
 */

#include "machine.h"
int main(void) {
  Message* msg = AllocMessage(10240);
  Target target;
  target.protocol = SOCKET_PROTOCOL;
  RegirstTarget(&target);
  memcpy(msg->buffer,"hello world",11);
  Request(msg,&target);
  return 0;
}
