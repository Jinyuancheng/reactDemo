/**************************************************************
 * @file main.cpp
 * @date 2019/08/15 9:09
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief	��ӡ�����е�"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָһ����λ�������λ���������͵��ڸ��� ����
			���磺153��һ��"ˮ�ɻ���"����Ϊ153=1�����η���5�����η���3�����η���
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
			std::cout << "ˮ�ɻ��� : " << i << std::endl;
		}
	}

	system("pause");
	return 0;
}