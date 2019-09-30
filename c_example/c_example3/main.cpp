/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/14 10:33		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ��Ŀ��һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�		
	x + 100 = n2, x + 100 + 168 = m2
	m2 - n2 = (x + 100 + 168) - (x + 100)
	m2 - n2 = 168 = (m + n)(m - n)
	���� : m + n = i m - n = j;
		   n = m -j; i = m + m -j;
		   i + j = 2m;

***************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc,char *argv[])
{
	int iX, iY;
	for (int iNum = 0; iNum < 10000; iNum++)
	{
		iX = sqrt(iNum + 100);
		iY = sqrt(iNum + 100 + 168);
		if (iX * iX == (iNum + 100) && iY * iY == (iNum + 100 + 168))
		{
			std::cout << "iNum : " << iNum << std::endl;
		}
	}
	system("pause");
	return 0;
}