#include <iostream>
#include <thread>
using namespace std;

void Printf(int _a, std::string _b)
{
	std::cout << _a << "   " << _b.c_str() << std::endl;
}

int main(int argc, char *argv[])
{
	std::thread oThread(Printf, 1, "jinzi");



	system("pause");
	return 0;
}