#include <iostream>
using namespace std;

class CTeach
{
private:
	int id;
	std::string name;
};

class CStudent
{
	 friend class CTeach;
public:

};

int main(int argc,char *argv[])
{
	system("pause");
	return 0;
}