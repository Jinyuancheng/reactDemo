#include "../include/TcpServer.h"


int main()
{
	unsigned short usPort = 10086;
	TcpServer server;
	/*\ 初始化结构体信息 \*/
	TcpServerInit(server);
	/*\ 绑定ip端口并监听 \*/
	if (TcpServerBindAndListen(server, usPort) == -1)
	{
		printf("Server Listen Port : %d Error\n", usPort);
	}
	else
	{
		printf("Server Listen Port : %d Success\n", usPort);
		/*\ 进行轮询处理数据 \*/
		TcpServerEpoll(server);
	}
	
	return 0;
}