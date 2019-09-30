/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/15 8:33		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 题目：古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，
				小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子
				总数为多少？（输出前40个月即可） 规律 : 1 1 2 3 5 8 13 21				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int iFirstMouth = 1;	/*\ 第一个月 \*/
	int iSecondMouth = 1;	/*\ 第二个月 \*/
	for (int i = 1; i < 40/2; i++)
	{
		iFirstMouth += iSecondMouth;
		iSecondMouth += iFirstMouth;
		std::cout << iFirstMouth << " " << std::endl;
		std::cout << iSecondMouth << " " << std::endl;
	}
	system("pause");
	return 0;
}