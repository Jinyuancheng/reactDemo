#pragma once
#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#define MAXSIZE 10000

//TcpServer基本信息
typedef struct 
{
	int					m_iServerFd;		/*\ 服务器监听句柄 \*/
	int					m_iClientFd;		/*\ 客户端与服务器的连接句柄 \*/
	int					m_iEpollFd;			/*\ epoll句柄 \*/
	int					m_iEpollEventNum;	/*\ 发生的事件的个数 \*/
	socklen_t			m_ClientAddrLen;	/*\ 存储客户端数据的结构体的长度 \*/
	struct sockaddr_in	m_ServerAddr;		/*\ 存储服务器数据的结构体 \*/
	struct sockaddr_in	m_ClientAddr;		/*\ 存储客户端数据的结构体 \*/
	struct epoll_event	m_Event;			/*\ 存储epoll事件 \*/
	struct epoll_event	m_Events[MAXSIZE];			/*\ 存储epoll事件的集合 \*/
}TcpServer,*pTcpServer;
///////////////////// 服务器的操作BEGIN /////////////////////////////////////////////////////
/*\ 初始化TcpServer \*/
void TcpServerInit(TcpServer _TcpServer);
/*\ 设置绑定和监听 \*/
int TcpServerBindAndListen(TcpServer _TcpServer, unsigned short _Port);
/*\ 使用epoll模型进行轮询 \*/
int TcpServerEpoll(TcpServer _TcpServer);
///////////////////// 服务器的操作END /////////////////////////////////////////////////////
#endif