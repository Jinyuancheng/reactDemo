#include "./include/http/BasicHttp.h"
static const char* gPort = "10086";
#include <windows.h>
int main(int argc,char *argv[])
{
	BasicHttp* iBasicHttp = new BasicHttp();
	//��ʼ��
	iBasicHttp->ManagerInit();
	//�󶨼����˿�
	iBasicHttp->ManagerBind(gPort);
	//����http
	iBasicHttp->ManagerSetHttp();
	//��ѯ
	iBasicHttp->ManagerPoll();

	return 0;
}