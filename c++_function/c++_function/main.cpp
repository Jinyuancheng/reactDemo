#include <iostream>
#include <functional>
using namespace std;

void demo()
{
	std::cout << "Hello World" << std::endl;
}

int add(int& iA, int& iB)
{
	return iA + iB;
}

class CDemo
{
public:
	CDemo() {};
public:
	void CDemoTest() { std::cout << "DemoTest" << std::endl; };
	int CDemoAdd(int& iA, int& iB) { return iA + iB; }
protected:
private:
};

int main(int argc, char *argv[])
{
	std::function<void(void)> funcFunc;
	std::function<int(int&, int&)> funcFunc1;
	CDemo oDemo;
	int a = 10;
	int b = 20;
	funcFunc = demo;
	funcFunc();
	/*\ 绑定成员函数 \*/
	funcFunc = std::bind(&CDemo::CDemoTest, &oDemo);
	funcFunc();
	funcFunc1 = add;
	int num = funcFunc1(a, b);
	std::cout << "num = " << num << std::endl;
	funcFunc1 = std::bind(&CDemo::CDemoAdd, &oDemo, std::placeholders::_1, std::placeholders::_2);
	int numb = funcFunc1(a, b);
	std::cout << "numb = " << numb << std::endl;
	auto funcFunc2 = std::bind(&CDemo::CDemoAdd, &oDemo, std::placeholders::_1, 20);
	int numc = funcFunc2(b);
	std::cout << "numc = " << numc << std::endl;
	system("pause");
	return 0;
}