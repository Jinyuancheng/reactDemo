#include "../include/TcpServer.h"


int main()
{
	unsigned short usPort = 10086;
	TcpServer server;
	/*\ ��ʼ���ṹ����Ϣ \*/
	TcpServerInit(server);
	/*\ ��ip�˿ڲ����� \*/
	if (TcpServerBindAndListen(server, usPort) == -1)
	{
		printf("Server Listen Port : %d Error\n", usPort);
	}
	else
	{
		printf("Server Listen Port : %d Success\n", usPort);
		/*\ ������ѯ�������� \*/
		TcpServerEpoll(server);
	}
	
	return 0;
}