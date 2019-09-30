/**************************************************************
 * @file main.cpp
 * @date 2019/08/14 9:53
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief

	企业发放的奖金根据利润提成。
	利润(I)低于或等于10万元时，奖金可提10%；
	利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
	20万到40万之间时，高于20万元的部分，可提成5%；
	40万到60万之间时高于40万元的部分，可提成3%；
	60万到100万之间时，高于60万元的部分，可提成1.5%；
	高于100万元时，超过100万元的部分按1%提成。
	从键盘输入当月利润I，求应发放奖金总数？
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
	double dbProfit = 0;	/*\ 利润 \*/
	double dbBonus = 0;		/*\ 奖金 \*/
	std::cout << "请输入利润值 : " << std::endl;
	std::cin >> dbProfit;
	/*\ 低于10万元 \*/
	if (dbProfit > 0 && dbProfit <= ONEWAN)
	{
		dbBonus += dbProfit * 0.1;
		goto END;
	}
	/*\ 大于10万小于20万 \*/
	else if (dbProfit > ONEWAN && dbProfit <= TWOWAN)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += (dbProfit - ONEWAN) * 0.075;
		goto END;
	}
	/*\ 大于20万小于40万 \*/
	else if (dbProfit > TWOWAN && dbProfit <= FOURWAN)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += (dbProfit - TWOWAN) * 0.05;
		goto END;
	}
	/*\ 大于40万小于60万 \*/
	else if (dbProfit > FOURWAN && dbProfit <= SIXWAN)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += FOURWAN * 0.05;
		dbBonus += (SIXWAN - FOURWAN) * 0.03;
		goto END;
	}
	/*\ 大于60万 小于100万 \*/
	else if (dbProfit > SIXWAN && dbProfit <= MILLION)
	{
		dbBonus += ONEWAN * 0.1;
		dbBonus += TWOWAN * 0.075;
		dbBonus += FOURWAN * 0.05;
		dbBonus += SIXWAN * 0.03;
		dbBonus += (MILLION - SIXWAN) * 0.015;
		goto END;
	}
	/*\ 大于100万 \*/
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
	std::cout << "利润 : " << dbProfit << "		奖金 : " << dbBonus << std::endl;
	system("pause");
	return 0;
}
