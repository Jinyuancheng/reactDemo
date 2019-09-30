CC = g++
CFLAGS = -Wall -pthread  -g 

#lib文件夹
LIBDIR = lib
#bin文件夹用来存储生成的可执行文件
BINDIR = bin
OBJDIR = $(BINDIR)/obj
#生成可执行文件的名字
TARGET = $(BINDIR)/HttpServer
#文件的目录结构
INCLUDE += 	include
#			Include/Event \
#			Include/Http \
#			Include/Log	\
#			Include/Mutex \
#			Include/Queue \
#			Include/Socket \
#			Include/ThreadPool \
#			Include/Utils

SRCDIR += src
#SRCDIR += Src/Cond
#SRCDIR += Src/Event
#SRCDIR += Src/Http
#SRCDIR += Src/Mutex
#SRCDIR += Src/Socket
#SRCDIR += Src/ThreadPool
#调用mk文件
include allrules.mk
