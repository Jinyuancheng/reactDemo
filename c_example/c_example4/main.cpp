/**************************************************************
 * @file main.cpp
 * @date 2019/08/14 17:30
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 输入某年某月某日，判断这一天是这一年的第几天？
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int Year, Mouth, Day, Num = 0;
	bool IsLeap = false;
	std::cout << "请输入年份 : " << std::endl;
	std::cin >> Year;
	std::cout << "请输入月份 : " << std::endl;
	std::cin >> Mouth;
	std::cout << "请输入天 : " << std::endl;
	std::cin >> Day;

	/*\ 判断是否是闰年 \*/
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
	{
		IsLeap = true;
	}

	/*\ 判断是第几月，计算出多少天 \*/
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

	//如果是闰年的话加一
	if (IsLeap)
	{
		Num++;
	}

	std::cout << "对应的天数 : " << Num << std::endl;
	system("pause");
	return 0;
}