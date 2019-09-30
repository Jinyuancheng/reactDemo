/**************************************************************
 * @file main.cpp
 * @date 2019/08/20 10:39
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��������string
***************************************************************/
#include <iostream>
#include <string>
using namespace std;

///////////////////// 2019/08/20 10:57:50 ���������� ==> BEGIN /////////////////////////////////////////////////////
/*\ iterator������� \*/
void FuncDemo1(string& sStr);
/*\ reverse_iterator������� \*/
void FuncDemo2(string& sStr);
/*\ ��ʹ�õ��������б��� \*/
void FuncDemo3(string& sStr);
/*\ �����õ��������з������ \*/
void FuncDemo4(string& sStr);
///////////////////// 2019/08/20 10:57:50 ���������� ==> END /////////////////////////////////////////////////////

///////////////////// 2019/08/20 10:58:10 �������� ==> BEGIN /////////////////////////////////////////////////////
/*\ �����Ĳ��� \*/
void FuncDemo5(string& sStr);
///////////////////// 2019/08/20 10:58:10 �������� ==> END /////////////////////////////////////////////////////

///////////////////// 2019/08/20 11:09:57 Ԫ�ط��� ==> BEGIN /////////////////////////////////////////////////////
/*\ Ԫ�ط��� \*/
void FuncDemo6(string& sStr);
///////////////////// 2019/08/20 11:09:57 Ԫ�ط��� ==> END /////////////////////////////////////////////////////

void FuncDemo7();
int main(int argc, char *argv[])
{
	string sName = "jinzi";
	///////////////////// 2019/08/20 10:58:42 ���������� ==> BEGIN /////////////////////////////////////////////////////
	/*FuncDemo1(sName);
	FuncDemo2(sName);
	FuncDemo3(sName);
	FuncDemo4(sName);*/
	///////////////////// 2019/08/20 10:58:42 ���������� ==> END /////////////////////////////////////////////////////

	///////////////////// 2019/08/20 10:59:12 �������� ==> BEGIN /////////////////////////////////////////////////////
	//FuncDemo5(sName);
	///////////////////// 2019/08/20 10:59:12 �������� ==> END /////////////////////////////////////////////////////
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
	//���ַ�����ȡ���ڼ����ַ���0��ʼ
	char name = sStr.at(2);
	std::cout << name << std::endl;
	/*\ ���ַ�����ȡ����һ��Ԫ�� \*/
	char first = sStr.front();
	/*\ ���ַ�����ȡ�����һ��Ԫ�� \*/
	char end = sStr.back();
	std::cout << first << "   " << end << std::endl;
	std::cout << "================================================" << std::endl;
	//ͬsStr.c_str();
	std::cout << "sStr.data() = " << sStr.data() << std::endl;
}

void FuncDemo5(string& sStr)
{
	if (!sStr.empty())
	{
		std::cout << "size() = " << sStr.size() << std::endl;
		std::cout << "length() = " << sStr.length() << std::endl;
		std::cout << "max_size() = " << sStr.max_size() << std::endl;
		/*\ ������С \*/
		sStr.resize(10);
		std::cout << "size() = " << sStr.size() << std::endl;
		std::cout << "length() = " << sStr.length() << std::endl;
		std::cout << "max_size() = " << sStr.max_size() << std::endl;
		/*\ ���ط���Ĵ洢��С \*/
		std::cout << sStr.capacity() << std::endl;
		/*\ �����ڴ� \*/
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
