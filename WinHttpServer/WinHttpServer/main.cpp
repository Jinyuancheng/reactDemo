#include "./include/http/BasicHttp.h"
static const char* gPort = "10086";
#include <windows.h>
int main(int argc,char *argv[])
{
	BasicHttp* iBasicHttp = new BasicHttp();
	//³õÊ¼»¯
	iBasicHttp->ManagerInit();
	//°ó¶¨¼àÌý¶Ë¿Ú
	iBasicHttp->ManagerBind(gPort);
	//ÉèÖÃhttp
	iBasicHttp->ManagerSetHttp();
	//ÂÖÑ¯
	iBasicHttp->ManagerPoll();

	return 0;
}