CC = g++
CFLAGS = -Wall -pthread  -g

LIBDIR = lib
BINDIR = bin
OBJDIR = $(BINDIR)/obj
TARGET = $(BINDIR)/c_tcpserver

INCLUDE += 	include \
			#Include/Event \
			Include/Http \
			Include/Log	\
			Include/Mutex \
			Include/Queue \
			Include/Socket \
			Include/ThreadPool \
			Include/Utils

SRCDIR += src \
#SRCDIR += Src/Cond \
SRCDIR += Src/Event \
SRCDIR += Src/Http \
SRCDIR += Src/Mutex \
SRCDIR += Src/Socket \
SRCDIR += Src/ThreadPool 

include allrules.mk
