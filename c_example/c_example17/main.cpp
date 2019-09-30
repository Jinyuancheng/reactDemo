/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/20 10:05		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 一球从100米高度自由落下，每次落地后反跳回原高度的一半；
			再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	float iHeight = 100;
	int iNum = 0;
	std::cout << "请输入弹跳几次 : " << std::endl;
	std::cin >> iNum;
	if (iNum > 0)
	{
		for (int i = 0; i < iNum; i++)
		{
			iHeight = 100 / 2;
		}
	}
	std::cout << "反弹高度 : " << iHeight << std::endl;


	system("pause");
	return 0;
}
