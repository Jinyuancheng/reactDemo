/**************************************************************
 * @file main.cpp
 * @date 2019/08/29 11:49
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 该demo演示了 如何生成一批线程 然后等待其完成
***************************************************************/
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

void Print(int _iNum)
{
	std::cout << _iNum << std::endl;
}

int main(int argc, char *argv[])
{
	std::vector<std::thread> vecThreads;
	for (int i = 0; i < 10; i++)
	{
		vecThreads.push_back(std::thread(Print, i));
	}
	std::for_each(vecThreads.begin(), vecThreads.end(),
		std::mem_fn(&std::thread::join));
	system("pause");
	return 0;
}