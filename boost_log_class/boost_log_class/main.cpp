#include <iostream>
#include "boost_log.h"
using namespace std;

int main(int argc, char *argv[])
{
	CBoostLog::GetInstance()->Init("jinzi.log");
	while (1)
	{
		CBoostLog::GetInstance()->WriteLog(critical, "����һ����������1");
	}
	system("pause");
	return 0;
}