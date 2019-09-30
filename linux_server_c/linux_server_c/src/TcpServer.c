#include  "../include/TcpServer.h"

 /****************************************!
 *@brief  ��ʼ���������Ļ�����Ϣ
 *@author Jinzi
 *@date   2019/04/26 8:47:13
 *@param[in]  _TcpServer һ���洢������������Ϣ�Ľṹ��
 *@param[out] 
 *@return     
 ****************************************/
void TcpServerInit(TcpServer _TcpServer)
{
	_TcpServer.m_iClientFd = -1;
	_TcpServer.m_iServerFd = -1;
	_TcpServer.m_ClientAddrLen = sizeof(_TcpServer.m_ClientAddr);
	memset(&_TcpServer.m_ServerAddr, 0, sizeof(_TcpServer.m_ServerAddr));
	memset(&_TcpServer.m_ClientAddr, 0, sizeof(_TcpServer.m_ClientAddr));
	memset(&_TcpServer.m_Event, 0, sizeof(_TcpServer.m_Event));
	memset(&_TcpServer.m_Events, 0, sizeof(_TcpServer.m_Events));
}
 /****************************************!
 *@brief  �����������ð󶨺ͼ���
 *@author Jinzi
 *@date   2019/04/26 9:22:53
 *@param[in]  _TcpServer һ���洢������������Ϣ�Ľṹ��
			  _Port	�����˿�
 *@param[out] 
 *@return     
 ****************************************/
int TcpServerBindAndListen(TcpServer _TcpServer,unsigned short _Port)
{
	_TcpServer.m_iServerFd = socket(AF_INET, SOCK_STREAM, 0);
	if (_TcpServer.m_iServerFd < 0)
	{
		printf("TcpServer.c-->TcpServerBindAndListen-->socket Error\n");
		goto Error;
	}
	_TcpServer.m_ServerAddr.sin_family = AF_INET;
	_TcpServer.m_ServerAddr.sin_port = htons(_Port);
	_TcpServer.m_ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(_TcpServer.m_iServerFd, (struct sockaddr*)&_TcpServer.m_ServerAddr, 
		sizeof(_TcpServer.m_ServerAddr)) < 0)
	{
		printf("TcpServer.c-->TcpServerBindAndListen-->bind Error\n");
		goto Error;
	}
	if (listen(_TcpServer.m_iServerFd, 128))
	{
		printf("TcpServer.c-->TcpServerBindAndlisten-->listen Error\n");
		goto Error;
	}
	return _TcpServer.m_iServerFd;
Error:
	close(_TcpServer.m_iServerFd);
	return -1;
}
 /****************************************!
 *@brief  ʹ��linux epoll������ѯ
 *@author Jinzi
 *@date   2019/04/26 9:38:21
 *@param[in]  _TcpServer һ���洢������������Ϣ�Ľṹ��
 *@param[out] 
 *@return     
 ****************************************/
int TcpServerEpoll(TcpServer _TcpServer)
{
	_TcpServer.m_Event.data.fd = _TcpServer.m_iServerFd;
	_TcpServer.m_Event.events = EPOLLIN | EPOLLET;
	_TcpServer.m_iEpollFd = epoll_create(MAXSIZE);
	if (_TcpServer.m_iEpollFd < 0)
	{
		printf("TcpServer.c-->TcpServerEpoll-->epoll_create Error\n");
		goto Error;
	}
	/*\ ע���¼� \*/
	if (epoll_ctl(_TcpServer.m_iEpollFd, EPOLL_CTL_ADD, _TcpServer.m_iServerFd,
		&_TcpServer.m_Event) < 0)
	{
		printf("TcpServer.c-->TcpServerEpoll-->epoll_ctl page = 79 Error\n");
		goto Error;
	}
	while (1)
	{
		/*\ �ȴ��¼����� \*/
		_TcpServer.m_iEpollEventNum = epoll_wait(_TcpServer.m_iEpollFd, _TcpServer.m_Events, MAXSIZE, -1);
		if (_TcpServer.m_iEpollEventNum < 0)
		{
			printf("TcpServer.c-->TcpServerEpoll-->epoll_wait Error\n");
			goto Error;
		}
		if (_TcpServer.m_iEpollEventNum == 0)
		{
			continue;
		}
		for (int i = 0; i < _TcpServer.m_iEpollEventNum; i++)
		{
			/*\ ˵�����µ��������� \*/
			if (_TcpServer.m_Events[i].data.fd == _TcpServer.m_iServerFd)
			{
				_TcpServer.m_iClientFd = accept(_TcpServer.m_iServerFd, (struct sockaddr*)&_TcpServer.m_ClientAddr,
					&_TcpServer.m_ClientAddrLen);
				if (_TcpServer.m_iClientFd < 0)
				{
					printf("TcpServer.c-->TcpServerEpoll-->accept Error\n");
					goto Error;
				}
				printf("Client Ip:%s, Port:%d\n",inet_ntoa(_TcpServer.m_ClientAddr.sin_addr),
					ntohs(_TcpServer.m_ClientAddr.sin_port));
				char buf[40] = { 0 };
				sprintf(buf,"Client Connect Success\n");
				write(_TcpServer.m_iClientFd, buf, sizeof(buf));
				//���þ����ӵ��¼�������
				_TcpServer.m_Event.data.fd = _TcpServer.m_iClientFd;
				_TcpServer.m_Event.events = EPOLLIN | EPOLLET;
				if (epoll_ctl(_TcpServer.m_iEpollFd, EPOLL_CTL_ADD, _TcpServer.m_iClientFd, &_TcpServer.m_Event) < 0)
				{
					printf("TcpServer.c-->TcpServerEpoll-->epoll_ctl Error page = 117\n");
					goto Error;
				}
			}
			/*\ �ͻ��˷������� \*/
			else
			{
				char buf[100] = { 0 };
				if (read(_TcpServer.m_iClientFd, buf, sizeof(buf)) < 0)
				{
					printf("TcpServer.c-->TcpServerEpoll-->read Error\n");
					goto Error;
				}
				else if (read(_TcpServer.m_iClientFd, buf, sizeof(buf)) == 0)
				{
					printf("Client DisConnect\n");
					goto Error;
				}
				else
				{
					printf("Client Send Data = %s\n",buf);
					char buff[200] = { 0 };
					sprintf(buff,"Client Send Data Is : %s",buf);
					write(_TcpServer.m_iClientFd, buff, sizeof(buff));
				}
			}
		}
	}
Error:
	close(_TcpServer.m_iServerFd);
	close(_TcpServer.m_iEpollFd);
	close(_TcpServer.m_iClientFd);
	return -1;
}