/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/15 13:14		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 	��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"������6=1��2��3.����ҳ�1000���ڵ�����������			  
***************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char *argv[])
{
	std::vector<int> vecNum;
	std::vector<int>::iterator itVecNum = vecNum.begin();
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			for (int z = 1; j <= 1000; z++)
			{
				if (j * z == i)
				{
					for (itVecNum; itVecNum != vecNum.end(); itVecNum++)
					{

					}
				}
			}
		}
	}


	system("pause");
	return 0;
}