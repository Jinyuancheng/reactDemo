#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{

	int a = 1;
	if (a < 1)
	{
		goto Free;
	}
Free:
	std::cout << "jinzi" << std::endl;
	system("pause");
	return 0;
}