#include"../include/httplib.h"

#pragma GCC diagnostic error "-std=c++14"
using namespace httplib;

#include "../include/test.h"
//#include <stdio.h>
//#include <stdlib.h>
#ifndef PORT	
#define PORT 10086
#endif
int main(int argc,char *argv[])
{
	Server iHttpServer;

	iHttpServer.Get("/", [=](const Request& req, Response& res) {
		res.set_content("Hello World\n", "text/plain");
	});

	iHttpServer.listen("localhost", PORT);

	int a = Add(2, 3);
	printf("a = %d\n",a);
	system("echo pause");
	return 0;
}