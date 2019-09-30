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

//TcpServer������Ϣ
typedef struct 
{
	int					m_iServerFd;		/*\ ������������� \*/
	int					m_iClientFd;		/*\ �ͻ���������������Ӿ�� \*/
	int					m_iEpollFd;			/*\ epoll��� \*/
	int					m_iEpollEventNum;	/*\ �������¼��ĸ��� \*/
	socklen_t			m_ClientAddrLen;	/*\ �洢�ͻ������ݵĽṹ��ĳ��� \*/
	struct sockaddr_in	m_ServerAddr;		/*\ �洢���������ݵĽṹ�� \*/
	struct sockaddr_in	m_ClientAddr;		/*\ �洢�ͻ������ݵĽṹ�� \*/
	struct epoll_event	m_Event;			/*\ �洢epoll�¼� \*/
	struct epoll_event	m_Events[MAXSIZE];			/*\ �洢epoll�¼��ļ��� \*/
}TcpServer,*pTcpServer;
///////////////////// �������Ĳ���BEGIN /////////////////////////////////////////////////////
/*\ ��ʼ��TcpServer \*/
void TcpServerInit(TcpServer _TcpServer);
/*\ ���ð󶨺ͼ��� \*/
int TcpServerBindAndListen(TcpServer _TcpServer, unsigned short _Port);
/*\ ʹ��epollģ�ͽ�����ѯ \*/
int TcpServerEpoll(TcpServer _TcpServer);
///////////////////// �������Ĳ���END /////////////////////////////////////////////////////
#endif