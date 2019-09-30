/**************************************************************
 * @file main.cpp
 * @date 2019/08/14 17:44
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 输入三个整数x,y,z，请把这三个数由小到大输出。
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int iX, iY, iZ;
	std::cout << "输入三个整数x,y,z,按照从小到大输出 !!!" << std::endl;
	std::cout << "请输入 X : " << std::endl;
	std::cin >> iX;
	std::cout << "请输入 Y : " << std::endl;
	std::cin >> iY;
	std::cout << "请输入 Z : " << std::endl;
	std::cin >> iZ;

	if (iX > iY && iX > iZ)
	{
		if (iY > iZ)
		{
			std::cout << "从小到大输出 : " << iZ << "," << iY << "," << iX << std::endl;
		}
		else
		{
			std::cout << "从小到大输出 : " << iY << "," << iZ << "," << iX << std::endl;
		}
	}
	else if (iY > iX && iY > iZ)
	{
		if (iX > iZ)
		{
			std::cout << "从小到大输出 : " << iZ << "," << iX << "," << iY << std::endl;
		}
		else
		{
			std::cout << "从小到大输出 : " << iX << "," << iZ << "," << iY << std::endl;
		}
	}
	else if (iZ > iX && iZ > iY)
	{
		if (iX > iY)
		{
			std::cout << "从小到大输出 : " << iY << "," << iX << "," << iZ << std::endl;
		}
		else
		{
			std::cout << "从小到大输出 : " << iX << "," << iY << "," << iZ << std::endl;
		}
	}

	system("pause");
	return 0;
}