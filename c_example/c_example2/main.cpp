/**************************************************************
 * @file main.cpp
 * @date 2019/08/14 9:53
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief

	��ҵ���ŵĽ������������ɡ�
	����(I)���ڻ����10��Ԫʱ���������10%��
	�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��
	20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
	40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��
	60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%��
	����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
	�Ӽ������뵱������I����Ӧ���Ž���������
***************************************************************/

#include <iostream>
using namespace std;

#define ONEWAN	(10 * 10000)
#define TWOWAN  (20 * 10000)
#define FOURWAN	(40 * 10000)
#define SIXWAN	(60 * 10000)
#define MILLION (100 * 10000)

int main(int argc, char *argv[])
{
	double dbProfit = 0;	/*\ ���� \*/
	double dbBonus = 0;		/*\ ���� \*/
	std::cout << "����������ֵ : " << std::endl;
	std::cin >> dbProfit;
	/*\ ����10��Ԫ \*/
	if (dbProfit > 0 && dbProfit <= ONEWAN)
	{
		dbBonus += dbProfit * 0.1;
		goto END;
	}
	/*\ ����10��С��20�� \*/
	else if (dbProfit > ONEWAN && dbProfit <= TWOWAN)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += (dbProfit - ONEWAN) * 0.075;
		goto END;
	}
	/*\ ����20��С��40�� \*/
	else if (dbProfit > TWOWAN && dbProfit <= FOURWAN)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += (dbProfit - TWOWAN) * 0.05;
		goto END;
	}
	/*\ ����40��С��60�� \*/
	else if (dbProfit > FOURWAN && dbProfit <= SIXWAN)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += FOURWAN * 0.05;
		dbBonus += (SIXWAN - FOURWAN) * 0.03;
		goto END;
	}
	/*\ ����60�� С��100�� \*/
	else if (dbProfit > SIXWAN && dbProfit <= MILLION)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += FOURWAN * 0.05;
		dbBonus += SIXWAN * 0.03;
		dbBonus += (MILLION - SIXWAN) * 0.015;
		goto END;
	}
	/*\ ����100�� \*/
	else if (dbProfit > MILLION)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += FOURWAN * 0.05;
		dbBonus += SIXWAN * 0.03;
		dbBonus += MILLION * 0.015;
		dbBonus += (dbProfit - MILLION) * 0.01;
		goto END;
	}

END:
	std::cout << "���� : " << dbProfit << "		���� : " << dbBonus << std::endl;
	system("pause");
	return 0;
}
