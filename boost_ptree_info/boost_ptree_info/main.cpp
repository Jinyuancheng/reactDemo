#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>
using namespace std;
using namespace boost::property_tree;

void read_info(std::string _str) 
{
	ptree oParent, oChild;
	read_info(_str, oParent);
	std::string success = oChild.get<std::string>("name");
	std::cout << "success:" << success << std::endl;
}

int main(int argc, char* argv[])
{
	read_info("./config.info");

	system("pause");
	return 0;
}