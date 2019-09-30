#include <iostream>
#include <regex>

using namespace std;

int main(int argc,char *argv[])
{
	std::string str = "99911";
	std::string sRegNum = "(^[1-9]$)|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)| \
		(^[1-9][0-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9][0-9][0-9]$)";


	std::string str1 = "C:\\testji.txt";
	/*\ +前面的字表达式可匹配多次 \*/
	std::string sRegPath = "(^[a-zA-Z]:(/[a-zA-Z0-9]+)+).([a-zA-Z0-9]+)$|(^[a-zA-Z]:(\\\\[a-zA-Z0-9]+)+).([a-zA-Z0-9]+)$";


	if (std::regex_match(str1, std::regex(sRegPath)))
	{
		std::cout << "匹配" << std::endl;
	}
	else
	{
		std::cout << "不匹配" << std::endl;
	}
	system("pause");
	return 0;
}