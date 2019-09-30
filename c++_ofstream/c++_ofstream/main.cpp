#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	ofstream oStream;
	ifstream iStream;
	oStream.open("./config.txt", ios::app);
	if (oStream.is_open())
	{
		oStream << "jinzi\t\n";
		oStream << "jinzi1\t\n";
		oStream << "jinzi2\t\n";
		oStream.close();
	}
	else
	{
		std::cout << "文件打开失败" << std::endl;
	}

	iStream.open("./config.txt", ios::in);
	char Data[1024 * 10];
	memset(Data, 0, 1024);
	iStream >> Data;
	std::cout << "Data : " << Data << std::endl;
	iStream >> Data;
	std::cout << "Data : " << Data << std::endl;
	iStream >> Data;
	std::cout << "Data : " << Data << std::endl;
	iStream.close();

	system("pause");
	return 0;
}