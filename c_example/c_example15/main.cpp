/**************************************************************
 * @file main.cpp
 * @date 2019/08/15 11:13
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��Ŀ������һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	char chData;
	int iCharNum = 0;
	int iBlankNum = 0;
	int iNumberNum = 0;
	std::cout << "������һЩ�ַ� : " << std::endl;
	while (chData = getchar() != '\n')
	{
		/*\ �ж��ַ� \*/
		if (((chData > 'a') && (chData < 'z')) || ((chData > 'A') && (chData < 'Z')))
		{
			iCharNum++;
		}
		/*\ �жϿո� \*/
		else if (chData == ' ')
		{
			iBlankNum++;
		}
		/*\ �ж����� \*/
		else if ((chData > '0') && (chData < '9'))
		{
			iNumberNum++;
		}
	}
	std::cout << "�ַ����� : " << iCharNum << std::endl;
	std::cout << "�ո����� : " << iBlankNum << std::endl;
	std::cout << "�������� : " << iNumberNum << std::endl;

	system("pause");
	return 0;
}