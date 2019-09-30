/**************************************************************
 * @file main.cpp
 * @date 2019/09/09 11:16
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo用来掩饰 二分法
***************************************************************/
#include <iostream>
using namespace std;

/*\ 二分法 \*/
template<typename var>
var DichotomyMethod(var* _varArr, unsigned int _uiArrLen, var _varElement)
{
	unsigned int uiLow = 0;
	unsigned int uiHeight = _uiArrLen - 1;
	unsigned int uiMiddle = 0;
	var varIsSucc = 0;
	while (uiLow < uiHeight)
	{
		uiMiddle = (uiLow + uiHeight) / 2;
		if (_varElement == _varArr[uiMiddle])
		{
			return _varArr[uiMiddle];
		}
		else if (_varElement < _varArr[uiMiddle])
		{
			uiHeight = uiMiddle - 1;
		}
		else if (_varElement > _varArr[uiMiddle])
		{
			uiLow = uiMiddle + 1;
		}
	}
	return varIsSucc;
}

int main(int argc, char *argv[])
{
	int iArr[5] = { 1,2,3,4,5 };
	int iData = DichotomyMethod<int>(iArr, 5, 3);
	printf("iData : %d\n", iData);
	system("pause");
	return 0;
}