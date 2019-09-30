#include "../include/TcpServer.h"

#define PORT	10086

int main()
{
	TCP::TcpServer* Server = new TCP::TcpServer();
	if (Server->BindAndListen(PORT) == -1)
	{
		printf("Server Ip Bind Port Error\n");
	}
	else
	{
		printf("Server Listen Port :%d \n", PORT);
	}
	//ÂÖÑ¯
	Server->HandleEpoll();
	return 0;
}