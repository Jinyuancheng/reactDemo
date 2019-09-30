/**************************************************************
 * @file main.cpp
 * @date 2019/08/14 17:30
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int Year, Mouth, Day, Num = 0;
	bool IsLeap = false;
	std::cout << "��������� : " << std::endl;
	std::cin >> Year;
	std::cout << "�������·� : " << std::endl;
	std::cin >> Mouth;
	std::cout << "�������� : " << std::endl;
	std::cin >> Day;

	/*\ �ж��Ƿ������� \*/
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
	{
		IsLeap = true;
	}

	/*\ �ж��ǵڼ��£������������ \*/
	switch (Mouth)
	{
	case 1:
		Num = 31;
		break;
	case 2:
		Num = 31 + 28;
		break;
	case 3:
		Num = 31 + 28 + Day;
		break;
	case 4:
		Num = 31 + 28 + 31 + Day;
		break;
	case 5:
		Num = 31 + 28 + 31 + 30 + Day;
		break;
	case 6:
		Num = 31 + 28 + 31 + 30 + 31 + Day;
		break;
	case 7:
		Num = 31 + 28 + 31 + 30 + 31 + 30 + Day;
		break;
	case 8:
		Num = 31 + 28 + 31 + 30 + 31 + 30 + 31 + Day;
		break;
	case 9:
		Num = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + Day;
		break;
	case 10:
		Num = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + Day;
		break;
	case 11:
		Num = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + Day;
		break;
	case 12:
		Num = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + Day;
		break;
	}

	//���������Ļ���һ
	if (IsLeap)
	{
		Num++;
	}

	std::cout << "��Ӧ������ : " << Num << std::endl;
	system("pause");
	return 0;
}