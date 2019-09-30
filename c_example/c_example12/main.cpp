/**************************************************************
 * @file main.cpp
 * @date 2019/08/15 9:09
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief	打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。
			例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
***************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int iGeWei, iShiWei, iBaiWei, iNum;
	for (int i = 0; i < 1000; i++)
	{
		iGeWei = i % 10;
		iShiWei = (i / 10) % 10;
		iBaiWei = (i / 10) / 10;
		iNum = ((iGeWei * iGeWei * iGeWei) + (iShiWei * iShiWei * iShiWei) +
			(iBaiWei * iBaiWei * iBaiWei));
		if (iNum == i)
		{
			std::cout << "水仙花数 : " << i << std::endl;
		}
	}

	system("pause");
	return 0;
}