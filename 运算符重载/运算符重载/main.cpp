#include <iostream>
using namespace std;

class CStudent
{
public:
	CStudent(const CStudent& _Student) 
	{
		this->id = _Student.id;
		this->name = _Student.name;
		this->Math = _Student.Math;
	}
	CStudent(int _id, std::string _name, float _math)
		:id(_id), name(_name), Math(_math) {}
	~CStudent() {}
public:
	void operator=(const CStudent& _Student)
	{
		this->id = _Student.id;
		this->name = _Student.name;
		this->Math = _Student.Math;
	}
	bool operator>(const CStudent& _Student)
	{
		if (_Student.Math < this->Math)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const CStudent& _Student)
	{
		if (this->id == _Student.id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	void Print()
	{
		std::cout << "id : " << this->id << std::endl;
		std::cout << "name : " << this->name.c_str() << std::endl;
		std::cout << "Math : " << this->Math << std::endl;
	}
private:
	int id;
	std::string name;
	float Math;
};

int main(int argc, char *argv[])
{
	CStudent* oStu1 = new CStudent(1, "jinzi", 100);
	CStudent* oStu2 = new CStudent(2, "jinzi1", 50);
	CStudent* oStu3 = new CStudent(*oStu1);
	oStu3->Print();
	if (*oStu1 == *oStu3)
	{
		std::cout << "等于" << std::endl;
	}
	else
	{
		std::cout << "不等于" << std::endl;
	}
	if (*oStu1 > *oStu2)
	{
		std::cout << "大于" << std::endl;
	}
	else
	{
		std::cout << "不大于" << std::endl;
	}
	system("pause");
	return 0;
}