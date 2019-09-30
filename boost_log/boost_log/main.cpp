#include <iostream>
#include <boost/log/trivial.hpp>

using namespace std;

int main(int argc,char *argv[])
{
	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	system("pause");
	return 0;
}
