/**************************************************************
 * @file main.cpp
 * @date 2019/08/15 8:49
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief �ж�101��200֮���������
***************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{

	for (int i = 101; i <= 200; i++)
	{
		if ((sqrt(i) / 2) != 0)
		{
			std::cout << "���� : " << i << std::endl;
		}
	}


	system("pause");
	return 0;
}