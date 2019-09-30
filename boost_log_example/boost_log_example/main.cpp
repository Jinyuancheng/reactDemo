/**************************************************************
 * @file main.cpp										  
 * @date 2019/08/21 15:43		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 演示最简单的控制台输出日志信息				  
***************************************************************/
#include <iostream>
#include <boost/log/trivial.hpp>
using namespace std;

int main(int argc,char *argv[])
{
	// trace,
	/*debug,
		info,
		warning,
		error,
		fatal*/
	BOOST_LOG_TRIVIAL(severity_level::trace) << "test";
	BOOST_LOG_TRIVIAL(severity_level::debug) << "test";
	BOOST_LOG_TRIVIAL(severity_level::warning) << "test";
	BOOST_LOG_TRIVIAL(severity_level::error) << "test";
	BOOST_LOG_TRIVIAL(severity_level::fatal) << "test";

	system("pause");
	return 0;
}
