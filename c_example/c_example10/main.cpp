/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/15 8:33		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ��Ŀ���ŵ����⣨�������̣�����һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�
				С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ�����
				����Ϊ���٣������ǰ40���¼��ɣ� ���� : 1 1 2 3 5 8 13 21				  
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int iFirstMouth = 1;	/*\ ��һ���� \*/
	int iSecondMouth = 1;	/*\ �ڶ����� \*/
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