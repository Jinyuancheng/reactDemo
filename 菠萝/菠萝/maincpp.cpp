#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
	Student(int _id, std::string _name) :id(_id), name(_name) {}
	~Student() {}
public:
	bool operator==(Student& stu)
	{
		if (this->id == stu.id && this->name == stu.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	int id;
	std::string name;
};

int main(int argc, char *argv[])
{
	std::vector<Student> a;		//�洢��������
	std::vector<Student> b1;	//�洢�ĸ�����
	std::vector<Student> b2;	//�洢��������
	std::vector<Student> b3;	//�洢��������

	Student* stu1 = new Student(1, "boluo1");
	Student* stu2 = new Student(2, "boluo2");
	Student* stu3 = new Student(3, "boluo3");
	Student* stu4 = new Student(4, "boluo4");
	Student* stu5 = new Student(5, "boluo5");

	//��������ӵ���̬������
	a.push_back(*stu1);
	a.push_back(*stu2);
	a.push_back(*stu3);

	b1.push_back(*stu1);
	b1.push_back(*stu2);
	b1.push_back(*stu3);
	b1.push_back(*stu4);

	b2.push_back(*stu1);
	b2.push_back(*stu2);

	b3.push_back(*stu1);
	b3.push_back(*stu2);
	b3.push_back(*stu5);

	//��ʼ�жϣ�b > a��ʱ��max_size()������Ԫ�صĸ���
	if (a.max_size() < b1.max_size())
	{
		//���������������
		for (int i = 0; i < b1.max_size(); i++)
		{
			if (i <= a.max_size())
			{
				if (a[i] == b1[i])
				{
					continue;
				}
				else
				{
					//�����������Ԫ��
					a.push_back(b1[i]);
				}
			}
			else
			{
				a.push_back(b1[i]);
			}
		}
	}
	//a < b
	else
	{
		std::vector<Student>::iterator it = a.begin();
		for (int i = 0; i < a.max_size(); i++)
		{
			if (a[i] == b1[i])
			{
				continue;
			}
			else
			{
				//��������ɾ��Ԫ��
				a.erase(it + i);
			}
		}
	}


	system("pause");
	return 0;
}