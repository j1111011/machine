#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libmachine.la

#######################################
# Build information for each library

# Sources for libmachine
libmachine_la_SOURCES = machine.c message.c target.c event.c
# dsl_list.c int_dsl_list.c

# Linker options libTestProgram
libmachine_la_LDFLAGS = 

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libmachine_la_CPPFLAGS = -I$(top_srcdir)/include

