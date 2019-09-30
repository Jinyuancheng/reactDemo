#pragma once
#ifndef _TCPSERVER_H
#define _TCPSERVER_H
///////////////////// ������Ҫ��ͷ�ļ�BEGIN /////////////////////////////////////////////////////
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
///////////////////// ������Ҫ��ͷ�ļ�END /////////////////////////////////////////////////////

///////////////////// ʹ�õĺ�BEGIN /////////////////////////////////////////////////////
#define MAX_EVENTS	10000			//epoll��ѯ����¼���
///////////////////// ʹ�õĺ�END /////////////////////////////////////////////////////

///////////////////// �Զ�������BEGIN /////////////////////////////////////////////////////
typedef	int				SOCK_HANDLE;		/*\ socket��� \*/
typedef sockaddr_in		SOCK_SVRADDR;		/*\ �洢�������˵�ip�˿ڵ���Ϣ \*/
typedef sockaddr_in		SOCK_CLTADDR;		/*\ �洢�ͻ��˵�ip�˿ڵ���Ϣ \*/
typedef int				SOCK_RET;			/*\ �����жϺ���ִ�н���Ƿ���ȷ \*/
typedef socklen_t		SOCK_CLTLEN;		/*\ �ͻ��˽ṹ�峤�� \*/
typedef epoll_event		SOCK_EPOLLEVENT;	/*\ epoll�¼� \*/
typedef int				SOCK_EPOLLFD;		/*\ epoll�ļ���� \*/
typedef int				SOCK_EPOLLRETEVENT; /*\ ����epoll_wait��������ֵȷ��Ҫ��ʲô���� \*/
///////////////////// �Զ�������END /////////////////////////////////////////////////////

namespace TCP
{
	/*\ TcpServer \*/
	class TcpServer
	{
	public:
		TcpServer();
		~TcpServer();
	public:
		/*\ ��ip�˿ڵ� \*/
		SOCK_RET BindAndListen(short _Port);
		/*\ ��ѯepoll \*/
		SOCK_RET HandleEpoll();
	private:
		SOCK_HANDLE m_ServerFd;			/*\ ��������� \*/
		SOCK_HANDLE m_ClientFd;			/*\ �ͻ��˾�� \*/
		SOCK_SVRADDR m_ServerAddr;		/*\ �洢��������ip�˿���Ϣ \*/
		SOCK_CLTADDR m_ClientAddr;		/*\ �洢�ͻ��˵�ip�˿ڵ���Ϣ \*/
		SOCK_CLTLEN m_ClientAddrLen;	/*\ �洢�ͻ������ݵĽṹ��ĳ��� \*/
		SOCK_EPOLLEVENT m_Event, m_Events[MAX_EVENTS]; /*\ ����epoll�¼��� \*/
		SOCK_EPOLLFD m_EpollFd;			/*\ epoll���ļ���� \*/
		SOCK_EPOLLRETEVENT m_EpollRetEv;/*\ ����epoll_wait��������ֵȷ��Ҫ��ʲô����,-1ʧ�� 0 ��ʱ ������ʾһ���ж��ٸ�Ҫ������¼� \*/
		std::vector<SOCK_CLTLEN> m_VecClients;/*\ �洢�������ӵĿͻ��˾�� \*/
	};
}

#endif


