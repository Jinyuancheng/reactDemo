#include <iostream>
using namespace std;

//���ñ����ʼ��
int main(int argc,char *argv[])
{
	int A = 10;
	int &qA = A;

	qA = 20;
	std::cout << "A = " << A << std::endl;

	system("pause");
	return 0;
}