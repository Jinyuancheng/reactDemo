/**************************************************************
 * @file main.cpp
 * @date 2019/08/14 17:44
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ������������x,y,z���������������С���������
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int iX, iY, iZ;
	std::cout << "������������x,y,z,���մ�С������� !!!" << std::endl;
	std::cout << "������ X : " << std::endl;
	std::cin >> iX;
	std::cout << "������ Y : " << std::endl;
	std::cin >> iY;
	std::cout << "������ Z : " << std::endl;
	std::cin >> iZ;

	if (iX > iY && iX > iZ)
	{
		if (iY > iZ)
		{
			std::cout << "��С������� : " << iZ << "," << iY << "," << iX << std::endl;
		}
		else
		{
			std::cout << "��С������� : " << iY << "," << iZ << "," << iX << std::endl;
		}
	}
	else if (iY > iX && iY > iZ)
	{
		if (iX > iZ)
		{
			std::cout << "��С������� : " << iZ << "," << iX << "," << iY << std::endl;
		}
		else
		{
			std::cout << "��С������� : " << iX << "," << iZ << "," << iY << std::endl;
		}
	}
	else if (iZ > iX && iZ > iY)
	{
		if (iX > iY)
		{
			std::cout << "��С������� : " << iY << "," << iX << "," << iZ << std::endl;
		}
		else
		{
			std::cout << "��С������� : " << iX << "," << iY << "," << iZ << std::endl;
		}
	}

	system("pause");
	return 0;
}