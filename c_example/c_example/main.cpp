/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/14 9:46		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ��Ŀ����1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int iNum = 0;		/*\ �������� \*/
	int iThreadNum = 0; /*\ ��λ����ֵ \*/
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int z = 1; z <= 4; z++)
			{
				if (i != j && i != z && j != z)
				{
					iNum++;
					std::cout << "��λ�� : " << i * 100 + j * 10 + z << std::endl;
				}
			}
		}
	}
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	std::cout << "��λ������ : " << iNum << std::endl;
	system("pause");
	return 0;
}