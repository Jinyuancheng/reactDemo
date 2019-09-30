#include <iostream>
#include <map>
#include "Student.h"
using namespace std;

typedef std::shared_ptr<Student> Student_Ptr;

int main(int argc,char *argv[])
{
	ATTR attr;
	attr.height = 173;
	attr.weight = 184;
	Student_Ptr stu1(new Student(1, "jinzi", attr));
	Student_Ptr stu2(new Student(2, "jinzi", attr));
	Student_Ptr stu3(new Student(3, "jinzi", attr));
	Student_Ptr stu4(new Student(4, "jinzi", attr));
	Student_Ptr stu5(new Student(5, "jinzi", attr));
	stu1->Print();
	std::cout << "Use Count" << stu1.use_count() << std::endl;
	system("pause");
	return 0;
}