/**************************************************************
 * @file main.cpp
 * @date 2019/08/15 8:49
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 判断101到200之间的素数。
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
			std::cout << "素数 : " << i << std::endl;
		}
	}


	system("pause");
	return 0;
}