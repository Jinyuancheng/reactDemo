#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

class Student
{
public:
	Student() :width(108),height(170){};
	Student(float _width, float _height) :width(_width), height(_height) {};
	~Student() 
	{
		std::cout << "析构函数" << std::endl;
	}
	float* GetInfo()
	{
		float* info = (float*)malloc(sizeof(float) * 2);
		memset(info, 0, sizeof(info));
		info[0] = width;
		info[1] = height;
		return info;
	}
protected:
private:
	float width;
	float height;
};

using namespace std;

int main(int argc, char *argv[])
{
	float* Info = NULL;
	//初始化
	boost::shared_ptr<Student> sp_student(new Student());
	boost::scoped_ptr<Student> sp_student1(new Student(168,300));
	Info = sp_student->GetInfo();
	std::cout << "width : " << Info[0] << std::endl;
	std::cout << "height : " << Info[1] << std::endl;
	Info = sp_student1->GetInfo();
	std::cout << "width : " << Info[0] << std::endl;
	std::cout << "height : " << Info[1] << std::endl;
	std::cout << "count : " <<  sp_student.use_count() << std::endl;
	Student* c_student = sp_student.get();
	Info = c_student->GetInfo();
	std::cout << "width : " << Info[0] << std::endl;
	std::cout << "height : " << Info[1] << std::endl;
	/*\ 释放当前的对象 \*/
	sp_student.reset();
	free(Info);
	system("pause");
	return 0;
}