/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/15 8:28		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 打印楼梯，同时在楼梯上方打印两个笑脸。\1是笑脸				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	std::cout << "\1\1" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}