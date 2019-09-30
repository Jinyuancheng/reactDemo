/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/14 17:58		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief Êä³ö9*9¿Ú¾÷¡£				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << std::left << i << " * " << j << " = " << i * j << " ";
		}
		std::cout << std::endl;
	}


	system("pause");
	return 0;
}