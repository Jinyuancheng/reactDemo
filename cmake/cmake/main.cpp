#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include "./student/student.h"
using namespace std;

void method()
{
	boost::shared_ptr<Student> stu1(new Student());
	stu1->printf();
}

int main(int argc,char *argv[])
{
	boost::thread thread1(method);
	shared_ptr<Student> stu1(new Student());
	boost::shared_ptr<Student> stu2(new Student());
	thread1.join();
	stu2->printf();
	stu1->printf();
	return 0;
}