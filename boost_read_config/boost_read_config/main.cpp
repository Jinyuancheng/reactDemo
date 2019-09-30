#include <iostream>

#include "./SaveIniData.h"
#include "./ReadJsonData.h"

using namespace std;
std::string gl_IniName = "./config.ini";
std::string gl_JsonName = "./config.json";
int main(int argc, char* argv[])
{
	shared_ptr<CSaveIniData> SaveIniHandle(new CSaveIniData(gl_IniName));
	std::cout << "data : " << SaveIniHandle->toString() << std::endl;
	system("pause");
	return 0;
}