/**************************************************************
 * @file main.cpp
 * @date 2019/08/20 10:39
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 用来测试string
***************************************************************/
#include <iostream>
#include <string>
using namespace std;

///////////////////// 2019/08/20 10:57:50 迭代器操作 ==> BEGIN /////////////////////////////////////////////////////
/*\ iterator正序遍历 \*/
void FuncDemo1(string& sStr);
/*\ reverse_iterator反序遍历 \*/
void FuncDemo2(string& sStr);
/*\ 不使用迭代器进行遍历 \*/
void FuncDemo3(string& sStr);
/*\ 不适用迭代器进行反向遍历 \*/
void FuncDemo4(string& sStr);
///////////////////// 2019/08/20 10:57:50 迭代器操作 ==> END /////////////////////////////////////////////////////

///////////////////// 2019/08/20 10:58:10 容量操作 ==> BEGIN /////////////////////////////////////////////////////
/*\ 容量的操作 \*/
void FuncDemo5(string& sStr);
///////////////////// 2019/08/20 10:58:10 容量操作 ==> END /////////////////////////////////////////////////////

///////////////////// 2019/08/20 11:09:57 元素访问 ==> BEGIN /////////////////////////////////////////////////////
/*\ 元素访问 \*/
void FuncDemo6(string& sStr);
///////////////////// 2019/08/20 11:09:57 元素访问 ==> END /////////////////////////////////////////////////////

void FuncDemo7();
int main(int argc, char *argv[])
{
	string sName = "jinzi";
	///////////////////// 2019/08/20 10:58:42 迭代器操作 ==> BEGIN /////////////////////////////////////////////////////
	/*FuncDemo1(sName);
	FuncDemo2(sName);
	FuncDemo3(sName);
	FuncDemo4(sName);*/
	///////////////////// 2019/08/20 10:58:42 迭代器操作 ==> END /////////////////////////////////////////////////////

	///////////////////// 2019/08/20 10:59:12 容量操作 ==> BEGIN /////////////////////////////////////////////////////
	//FuncDemo5(sName);
	///////////////////// 2019/08/20 10:59:12 容量操作 ==> END /////////////////////////////////////////////////////
	//FuncDemo6(sName);
	system("pause");
	return 0;
}

void FuncDemo7()
{
	string User = "{\"user\":\"jinzi\"}";



}

void FuncDemo6(string& sStr)
{
	//从字符串中取出第几个字符从0开始
	char name = sStr.at(2);
	std::cout << name << std::endl;
	/*\ 从字符串中取出第一个元素 \*/
	char first = sStr.front();
	/*\ 从字符串中取出最后一个元素 \*/
	char end = sStr.back();
	std::cout << first << "   " << end << std::endl;
	std::cout << "================================================" << std::endl;
	//同sStr.c_str();
	std::cout << "sStr.data() = " << sStr.data() << std::endl;
}

void FuncDemo5(string& sStr)
{
	if (!sStr.empty())
	{
		std::cout << "size() = " << sStr.size() << std::endl;
		std::cout << "length() = " << sStr.length() << std::endl;
		std::cout << "max_size() = " << sStr.max_size() << std::endl;
		/*\ 调整大小 \*/
		sStr.resize(10);
		std::cout << "size() = " << sStr.size() << std::endl;
		std::cout << "length() = " << sStr.length() << std::endl;
		std::cout << "max_size() = " << sStr.max_size() << std::endl;
		/*\ 返回分配的存储大小 \*/
		std::cout << sStr.capacity() << std::endl;
		/*\ 缩减内存 \*/
		sStr.shrink_to_fit();
		std::cout << sStr.capacity() << std::endl;
	}
}

void FuncDemo4(string& sStr)
{
	std::cout << "FuncDemo4=============================>Begin" << std::endl;
	for (auto itStr = sStr.crbegin(); itStr != sStr.crend(); itStr++)
	{
		std::cout << *itStr << std::endl;
	}
	std::cout << "FuncDemo4=============================>End" << std::endl;
}

void FuncDemo3(string& sStr)
{
	std::cout << "FuncDemo3=============================>Begin" << std::endl;
	for (auto itStr = sStr.cbegin(); itStr != sStr.cend(); itStr++)
	{
		std::cout << *itStr << std::endl;
	}
	std::cout << "FuncDemo3=============================>End" << std::endl;
}

void FuncDemo2(string& sStr)
{
	std::cout << "FuncDemo2=============================>Begin" << std::endl;
	string::reverse_iterator itStr = sStr.rbegin();
	for (itStr; itStr != sStr.rend(); itStr++)
	{
		std::cout << *itStr << std::endl;
	}
	std::cout << "FuncDemo2=============================>End" << std::endl;

}

void FuncDemo1(string& sStr)
{
	std::cout << "FuncDemo1=============================>Begin" << std::endl;
	string::iterator itName = sStr.begin();
	for (itName; itName != sStr.end(); itName++)
	{
		std::cout << *itName << std::endl;
	}
	std::cout << "FuncDemo1=============================>End" << std::endl;
}
