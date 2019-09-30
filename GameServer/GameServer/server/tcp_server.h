#pragma once
#ifndef _TCPSERVER_H
#define _TCPSERVER_H
///////////////////// 引用需要的头文件BEGIN /////////////////////////////////////////////////////
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <vector>
///////////////////// 引用需要的头文件END /////////////////////////////////////////////////////

///////////////////// 使用的宏BEGIN /////////////////////////////////////////////////////
#define MAX_EVENTS	10000			//epoll轮询最大事件数
///////////////////// 使用的宏END /////////////////////////////////////////////////////

///////////////////// 自定义类型BEGIN /////////////////////////////////////////////////////
typedef	int				SOCK_HANDLE;		/*\ socket句柄 \*/
typedef sockaddr_in		SOCK_SVRADDR;		/*\ 存储服务器端的ip端口等信息 \*/
typedef sockaddr_in		SOCK_CLTADDR;		/*\ 存储客户端的ip端口等信息 \*/
typedef int				SOCK_RET;			/*\ 用来判断函数执行结果是否正确 \*/
typedef socklen_t		SOCK_CLTLEN;		/*\ 客户端结构体长度 \*/
typedef epoll_event		SOCK_EPOLLEVENT;	/*\ epoll事件 \*/
typedef int				SOCK_EPOLLFD;		/*\ epoll文件句柄 \*/
typedef int				SOCK_EPOLLRETEVENT; /*\ 根据epoll_wait函数返回值确定要做什么事情 \*/
///////////////////// 自定义类型END /////////////////////////////////////////////////////

namespace TCP
{
	/*\ TcpServer \*/
	class TcpServer
	{
	public:
		TcpServer();
		~TcpServer();
	public:
		/*\ 绑定ip端口等 \*/
		SOCK_RET BindAndListen(short _Port);
		/*\ 轮询epoll \*/
		SOCK_RET HandleEpoll();
	private:
		SOCK_HANDLE m_ServerFd;			/*\ 服务器句柄 \*/
		SOCK_HANDLE m_ClientFd;			/*\ 客户端句柄 \*/
		SOCK_SVRADDR m_ServerAddr;		/*\ 存储服务器的ip端口信息 \*/
		SOCK_CLTADDR m_ClientAddr;		/*\ 存储客户端的ip端口等信息 \*/
		SOCK_CLTLEN m_ClientAddrLen;	/*\ 存储客户端数据的结构体的长度 \*/
		SOCK_EPOLLEVENT m_Event, m_Events[MAX_EVENTS]; /*\ 设置epoll事件等 \*/
		SOCK_EPOLLFD m_EpollFd;			/*\ epoll的文件句柄 \*/
		SOCK_EPOLLRETEVENT m_EpollRetEv;/*\ 根据epoll_wait函数返回值确定要做什么事情,-1失败 0 超时 其他表示一共有多少个要处理的事件 \*/
		std::vector<SOCK_CLTLEN> m_VecClients;/*\ 存储所有连接的客户端句柄 \*/
	};
}

#endif


