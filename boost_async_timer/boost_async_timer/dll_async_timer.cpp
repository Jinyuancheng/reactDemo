#include <iostream>
#include <windows.h>
using namespace std;
typedef struct
{
	int id;
	std::string name;
}STUDENT, * PSTUDENT;

typedef void(*Regist)(void(*)(STUDENT));

void Print(STUDENT _stu)
{
	std::cout << "id : " << _stu.id << std::endl;
	std::cout << "name : " << _stu.name << std::endl;
}

int main(int argc,char *argv[])
{
	HMODULE pHandle = LoadLibrary("./boost_timer_event_dll.dll");
	Regist reg = nullptr;
	if (pHandle != nullptr)
	{
		reg = (Regist)GetProcAddress(pHandle, "regist_callback_func");
	}
	reg(Print);
	system("pause");
	return 0;
}