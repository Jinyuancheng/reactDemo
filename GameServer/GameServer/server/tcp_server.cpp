#include "./Tcp_Server.h"

/****************************************!
*@brief  绑定监听句柄
*@author Jinzi
*@date   2019/04/25 10:56:33
*@param[in]  _Port监听端口
*@param[out]
*@return 失败返回-1 成功返回大于0的值
****************************************/
SOCK_RET TCP::TcpServer::BindAndListen(short _Port)
{
	int ret = -1;
	/*\ 初始化socket \*/
	this->m_ServerFd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->m_ServerFd < 0)
	{
		printf("TcpServer.cpp-->BindAndListen-->socket Error\n");
		goto Err;
	}
	this->m_ServerAddr.sin_family = AF_INET;
	this->m_ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->m_ServerAddr.sin_port = htons(_Port);
	/*\ 绑定ip和端口 \*/
	ret = bind(this->m_ServerFd, (const sockaddr*)&this->m_ServerAddr, sizeof(this->m_ServerAddr));
	if (ret < 0)
	{
		printf("TcpServer.cpp-->BindAndListen-->bind Error\n");
		goto Err;
	}
	/*\ 监听事件 \*/
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
*@brief  使用linux epoll模型进行轮询处理数据
*@author Jinzi
*@date   2019/04/25 11:16:00
*@param[in]
*@param[out]
*@return    失败返回-1
****************************************/
SOCK_RET TCP::TcpServer::HandleEpoll()
{
	int ret = -1;
	this->m_Event.data.fd = this->m_ServerFd;
	this->m_Event.events = EPOLLIN | EPOLLET;
	//创建epoll模型返回epoll一个句柄
	this->m_EpollFd = epoll_create(MAX_EVENTS);
	if (this->m_EpollFd < 0)
	{
		printf("TcpServer.cpp-->HandleEpoll-->epoll_create Error\n");
		goto Err;
	}
	/*\ 添加事件 \*/
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
			// 客户端有新的连接请求
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
				/*\ 将客户端句柄添加到epoll事件中 \*/
				this->m_Event.data.fd = this->m_ClientFd;
				this->m_Event.events = EPOLLET | EPOLLIN;
				if (epoll_ctl(this->m_EpollFd, EPOLL_CTL_ADD, this->m_ClientFd, &this->m_Event) < 0)
				{
					printf("TcpServer.cpp-->HandleEpoll-->epoll_ctl page=98 Error\n");
					goto Err;
				}
			}
			/*\ 客户端有数据发送过来 \*/
			else
			{
				char buf[100] = { 0 };
				/*\ 失败 \*/
				if (read(this->m_ClientFd, buf, sizeof(buf)) < 0)
				{
					printf("TcpServer-->HandleEpoll-->read Error\n");
					goto Err;
					/*\ 客户端断开连接 \*/
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
*@brief  TcpServer构造函数，初始化属性
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
*@brief  TcpServer析构函数
*@author Jinzi
*@date   2019/04/25 11:14:13
*@param[in]
*@param[out]
*@return
****************************************/
TCP::TcpServer::~TcpServer()
{

}
