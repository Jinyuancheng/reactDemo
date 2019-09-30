// boost_cmake.cpp: 定义应用程序的入口点。
//

#include "boost_cmake.h"
#include <memory>
using namespace std;

class Student {
public:
	Student() :name("jinzi"), school("woqu") {}
	void printf()
	{
		cout << "name : " << "jinzi" << endl;
		cout << "school : " << "Test" << endl;
	}
private:
	string name;
	string school;
};

int main()
{
	shared_ptr<Student> stu1(new Student());
	stu1->printf();
	cout << "Hello CMake。" << endl;
	return 0;
}
