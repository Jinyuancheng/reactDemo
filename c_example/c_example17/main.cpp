/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/20 10:05		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻
			�����£������ڵ�10�����ʱ�������������ף���10�η�����ߣ�				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	float iHeight = 100;
	int iNum = 0;
	std::cout << "�����뵯������ : " << std::endl;
	std::cin >> iNum;
	if (iNum > 0)
	{
		for (int i = 0; i < iNum; i++)
		{
			iHeight = 100 / 2;
		}
	}
	std::cout << "�����߶� : " << iHeight << std::endl;


	system("pause");
	return 0;
}
