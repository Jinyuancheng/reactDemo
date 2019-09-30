#include <iostream>
#include <functional>
using namespace std;

typedef int(*Func)(int, int);
typedef std::function<Func> testFunc;

class CTest
{
public:
	CTest(int a, int b) {
		m_Add = std::bind(&CTest::add, this, std::placeholders::_1, std::placeholders::_2);
		m_Add(a, b);
	}
	int add(int a, int b) { std::cout << "A + B =" << a + b << std::endl; return 0; }
protected:
private:
	testFunc m_Add;
};

int main(int argc, char *argv[])
{
	CTest test(1, 3);

	system("pause");
	return 0;
}