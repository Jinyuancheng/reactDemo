#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	/*1.创建socket*/
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("socket error");
		exit(1);
	}
	/*向serveraddr中填入服务器端ip、port和地址族类型(IPV4)*/
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(10086);
	//将IP地址转换成网络字节序后填入serveraddr中
	//inet_pton(AF_INET, argv[1], &serveraddr.sin_addr.s_addr);
	inet_aton("192.168.1.152", &serveraddr.sin_addr);
	/*2.客户端调用connect函数连接到服务器端*/
	if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
	{
		perror("connect error");
		exit(1);
	}
	printf("connect success\n");

	/*3.调用IO函数与服务器端进行通信*/
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	size_t size;
	if ((size = read(sockfd, buf, sizeof(buf))) < 0)
	{
		perror("read error");
	}
	printf("Server Callback Data Success\n");
	char buff[100] = { 0 };
	sprintf(buff,"Client Send Data ------------->\n");
	write(sockfd, buff, sizeof(buff));
	/*\ 关闭套接字 断开连接 \*/
	return 0;
}