#include <iostream>
#include <set> //�����ض�˳��洢ΨһԪ�ص�����
using namespace std;

int main(int argc, char *argv[])
{
	/*\ �洢Ψһ������ \*/
	std::set<std::string> setData;

	setData.insert("jinzi");
	/*\ �洢�ظ����ݣ������滻��������ж��δ洢 \*/
	setData.insert("jinzi");
	setData.insert("woqu");
	std::cout << "size() = " << setData.size() << std::endl;
	std::cout << "max_size() = " << setData.max_size() << std::endl;
	for (std::set<std::string>::iterator it = setData.begin();
		it != setData.end(); it++)
	{
		std::cout << it->c_str() << std::endl;
	}
	setData.clear();
	if (setData.empty())
	{
		std::cout << "����Ϊ��" << std::endl;
	}
	else
	{
		std::cout << "���ϲ�Ϊ��" << std::endl;
	}
	system("pause");
	return 0;
}