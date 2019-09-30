/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/14 9:46		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int iNum = 0;		/*\ 用来计数 \*/
	int iThreadNum = 0; /*\ 三位数的值 \*/
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int z = 1; z <= 4; z++)
			{
				if (i != j && i != z && j != z)
				{
					iNum++;
					std::cout << "三位数 : " << i * 100 + j * 10 + z << std::endl;
				}
			}
		}
	}
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	std::cout << "三位数总数 : " << iNum << std::endl;
	system("pause");
	return 0;
}