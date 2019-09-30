#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int iId;
	std::string sName;
	char chBuf[64];
	std::map<int, std::string> mapStudent;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "please input student id : " << std::endl;
		std::cin >> iId;
		std::cout << "please input student name : " << std::endl;
		memset(chBuf, 0, 64);
		std::cin >> chBuf;
		sName.clear();
		sName.append(chBuf);
		mapStudent.insert(std::pair<int, std::string>(iId, sName));
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	}
	std::cout << "########################################################" << std::endl;
	for (std::map<int, std::string>::iterator it = mapStudent.begin();
		it != mapStudent.end(); it++)
	{
		std::cout << "id : " << it->first << " ,name : " << it->second.c_str() << std::endl;
	}
	std::cout << "########################################################" << std::endl;
	std::map<int, std::string>::iterator it = mapStudent.find(1);
	if (it != mapStudent.end())
	{
		std::cout << "find student info : id = " << it->first << ", Name = " << it->second.c_str() << std::endl;
	}
	system("pause");
	return 0;
}