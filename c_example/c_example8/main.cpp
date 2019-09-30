/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/14 18:05		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 要求输出国际象棋棋盘。 8 * 8				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((j % 2) == 0)
			{
				std::cout << "A ";
			}
			else
			{
				std::cout << "B ";
			}
		}
		std::cout << std::endl;
	}


	system("pause");
	return 0;
}