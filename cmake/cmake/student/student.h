#pragma once
#include <iostream>
class Student
{
public:
	Student();
	~Student();
public :
	void printf()
	{
		std::cout << "id : " << this->id << std::endl;
		std::cout << "name : " << this->name << std::endl;
		std::cout << "school : " << this->school << std::endl;
	}
private:
	unsigned int id;
	std::string name;
	std::string school;
};

