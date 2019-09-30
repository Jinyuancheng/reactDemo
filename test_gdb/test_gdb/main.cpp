#include <iostream>
#include <boost/shared_ptr.hpp>
using namespace std;

class Student
{
public:
	Student() :id(1), name("jinzi"), school("woqu") {}
	Student(int _id, string _name, string _school) :id(_id), name(_name), school(_school) {}
public:
	void printf()
	{
		cout << "_id : " << this->id << endl;
		cout << "_name : " << this->name << endl;
		cout << "_school : " << this->school << endl;
	}
protected:
private:
	int id;
	string name;
	string school;
};

int main(int argc,char *argv[])
{
	boost::shared_ptr<Student> stu1(new Student());
	boost::shared_ptr<Student> stu2(new Student(2, "tom", "wocahei"));
	stu1->printf();
	stu2->printf();
	system("pause");
	return 0;
}