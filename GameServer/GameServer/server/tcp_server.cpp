#include "./Tcp_Server.h"

/****************************************!
*@brief  �󶨼������
*@author Jinzi
*@date   2019/04/25 10:56:33
*@param[in]  _Port�����˿�
*@param[out]
*@return ʧ�ܷ���-1 �ɹ����ش���0��ֵ
****************************************/
SOCK_RET TCP::TcpServer::BindAndListen(short _Port)
{
	int ret = -1;
	/*\ ��ʼ��socket \*/
	this->m_ServerFd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->m_ServerFd < 0)
	{
		printf("TcpServer.cpp-->BindAndListen-->socket Error\n");
		goto Err;
	}
	this->m_ServerAddr.sin_family = AF_INET;
	this->m_ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->m_ServerAddr.sin_port = htons(_Port);
	/*\ ��ip�Ͷ˿� \*/
	ret = bind(this->m_ServerFd, (const sockaddr*)&this->m_ServerAddr, sizeof(this->m_ServerAddr));
	if (ret < 0)
	{
		printf("TcpServer.cpp-->BindAndListen-->bind Error\n");
		goto Err;
	}
	/*\ �����¼� \*/
	ret = listen(this->m_ServerFd, SOMAXCONN);
	if (ret < 0)
	{
		printf("TcpServer.cpp-->BindAndListen-->listen Error\n");
		goto Err;
	}
	return ret;
Err:
	close(this->m_ServerFd);
	return ret;
}
/****************************************!
*@brief  ʹ��linux epollģ�ͽ�����ѯ��������
*@author Jinzi
*@date   2019/04/25 11:16:00
*@param[in]
*@param[out]
*@return    ʧ�ܷ���-1
****************************************/
SOCK_RET TCP::TcpServer::HandleEpoll()
{
	int ret = -1;
	this->m_Event.data.fd = this->m_ServerFd;
	this->m_Event.events = EPOLLIN | EPOLLET;
	//����epollģ�ͷ���epollһ�����
	this->m_EpollFd = epoll_create(MAX_EVENTS);
	if (this->m_EpollFd < 0)
	{
		printf("TcpServer.cpp-->HandleEpoll-->epoll_create Error\n");
		goto Err;
	}
	/*\ ����¼� \*/
	ret = epoll_ctl(this->m_EpollFd, EPOLL_CTL_ADD, this->m_ServerFd, &this->m_Event);
	if (ret < 0)
	{
		printf("TcpServer.cpp-->HandleEpoll-->epoll_ctl Error\n");
		goto Err;
	}
	while (1)
	{
		this->m_EpollRetEv = epoll_wait(this->m_EpollFd, this->m_Events, MAX_EVENTS, -1);
		if (this->m_EpollRetEv < 0)
		{
			printf("TcpServer.cpp-->HandleEpoll-->epoll_wait Error\n");
			goto Err;
		}
		if (this->m_EpollRetEv == 0)
		{
			continue;
		}
		for (int i = 0; i < this->m_EpollRetEv; i++)
		{
			// �ͻ������µ���������
			if (this->m_Events[i].data.fd == this->m_ServerFd)
			{
				this->m_ClientFd = accept(this->m_ServerFd, (sockaddr*)&this->m_ClientAddr, &this->m_ClientAddrLen);
				if (this->m_ClientFd < 0)
				{
					printf("TcpServer.cpp-->HandleEpoll-->accept Error\n");
					goto Err;
				}
				printf("Client Ip = %s, Port = %d\n", inet_ntoa(this->m_ClientAddr.sin_addr), ntohs(this->m_ClientAddr.sin_port));
				this->m_VecClients.push_back(this->m_ClientFd);
				char buf[100] = { 0 };
				sprintf(buf, "Client Ip = %s,Port = %d Connect Success\n",
					inet_ntoa(this->m_ClientAddr.sin_addr), ntohs(this->m_ClientAddr.sin_port));
				write(this->m_ClientFd, buf, sizeof(buf));
				/*\ ���ͻ��˾����ӵ�epoll�¼��� \*/
				this->m_Event.data.fd = this->m_ClientFd;
				this->m_Event.events = EPOLLET | EPOLLIN;
				if (epoll_ctl(this->m_EpollFd, EPOLL_CTL_ADD, this->m_ClientFd, &this->m_Event) < 0)
				{
					printf("TcpServer.cpp-->HandleEpoll-->epoll_ctl page=98 Error\n");
					goto Err;
				}
			}
			/*\ �ͻ��������ݷ��͹��� \*/
			else
			{
				char buf[100] = { 0 };
				/*\ ʧ�� \*/
				if (read(this->m_ClientFd, buf, sizeof(buf)) < 0)
				{
					printf("TcpServer-->HandleEpoll-->read Error\n");
					goto Err;
					/*\ �ͻ��˶Ͽ����� \*/
				}
				else if (read(this->m_ClientFd, buf, sizeof(buf)) == 0)
				{
					printf("Client DisConnect\n");
					close(this->m_ClientFd);
				}
				else
				{
					printf("Client Send Data = %s\n", buf);
					char buff[100] = { 0 };
					sprintf(buff, "Server Get Client Data!!\n");
					write(this->m_ClientFd, buff, sizeof(buff));
				}
			}
		}
	}
Err:
	close(this->m_ServerFd);
	close(this->m_EpollFd);
	close(this->m_ClientFd);
	ret = -1;
	return ret;
}
/****************************************!
*@brief  TcpServer���캯������ʼ������
*@author Jinzi
*@date   2019/04/25 10:51:51
*@param[in]
*@param[out]
*@return
****************************************/
TCP::TcpServer::TcpServer()
{
	this->m_ServerFd = -1;
	memset(&this->m_ServerAddr, 0, sizeof(this->m_ServerAddr));
	memset(&this->m_ClientAddr, 0, sizeof(this->m_ClientAddr));
	memset(&this->m_Event, 0, sizeof(this->m_Event));
	memset(&this->m_Events, 0, sizeof(this->m_Events));
}
/****************************************!
*@brief  TcpServer��������
*@author Jinzi
*@date   2019/04/25 11:14:13
*@param[in]
*@param[out]
*@return
****************************************/
TCP::TcpServer::~TcpServer()
{

}
