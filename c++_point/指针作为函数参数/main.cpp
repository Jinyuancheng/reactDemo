#include <iostream>
using namespace std;

void Add(int* p, int num)
{
	*p += num;
}

int main(int argc,char *argv[])
{
	int A = 20;
	int* pA = &A;
	Add(pA, 50);
	std::cout << "A = " << A << std::endl;
	system("pause");
	return 0;
}