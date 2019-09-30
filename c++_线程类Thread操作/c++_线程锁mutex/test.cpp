#include <iostream>
using namespace std;

class CStudent
{
public:
	//void operator=(CStudent&) = delete;
};

int main(int argc,char *argv[])
{
	CStudent C1;
	CStudent  C2;
	C1 = C2;
	system("pause");
	return 0;
}