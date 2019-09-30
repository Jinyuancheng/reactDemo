#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::stringstream ss;
	int length = 0;
	ifs.open("./config.txt", std::ios::in);
	ss << ifs.rdbuf();
	std::cout << "buf : " << ss.str() << std::endl;

	ofs.open("./test.txt", std::ios::app);
	ofs << ss.str();

	ifs.close();
	ofs.close();
	system("pause");
	return 0;
}