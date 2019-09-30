/**************************************************************
 * @file main.cpp
 * @date 2019/08/15 11:13
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	char chData;
	int iCharNum = 0;
	int iBlankNum = 0;
	int iNumberNum = 0;
	std::cout << "请输入一些字符 : " << std::endl;
	while (chData = getchar() != '\n')
	{
		/*\ 判断字符 \*/
		if (((chData > 'a') && (chData < 'z')) || ((chData > 'A') && (chData < 'Z')))
		{
			iCharNum++;
		}
		/*\ 判断空格 \*/
		else if (chData == ' ')
		{
			iBlankNum++;
		}
		/*\ 判断数字 \*/
		else if ((chData > '0') && (chData < '9'))
		{
			iNumberNum++;
		}
	}
	std::cout << "字符数量 : " << iCharNum << std::endl;
	std::cout << "空格数量 : " << iBlankNum << std::endl;
	std::cout << "数字数量 : " << iNumberNum << std::endl;

	system("pause");
	return 0;
}