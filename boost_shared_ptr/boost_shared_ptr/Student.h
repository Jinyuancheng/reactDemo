#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
typedef struct
{
	float weight;
	float height;
}ATTR, * PATTR;

class Student
{
public:
	Student(int _id, std::string _name, ATTR _attr) :m_id(_id), m_name(_name), m_attr(_attr) {}
	~Student() {}
public:
	void Print()
	{
		std::cout << "id : " << this->m_id << std::endl;
		std::cout << "name : " << this->m_name << std::endl;
		std::cout << "attr.weight : " << this->m_attr.weight << std::endl;
		std::cout << "attr.height : " << this->m_attr.height << std::endl;
	}
private:
	int m_id;
	std::string m_name;
	ATTR m_attr;
};

#endif