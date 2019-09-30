/**************************************************************
 * @file main.cpp
 * @date 2019/08/21 15:54
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 演示带有过滤器的控制台输出日志
***************************************************************/
#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
using namespace std;

namespace logging = boost::log;

int main(int argc, char *argv[])
{
	/*\ 设置全局的过滤器，get()方法得到核心的单例模式的一个操作对象，用来进行操作 \*/
	logging::core::get()->set_filter(
		/*\ 设置过滤器等级 \*/
		logging::trivial::severity >= logging::trivial::info
	);

	BOOST_LOG_TRIVIAL(severity_level::trace) << "test";
	BOOST_LOG_TRIVIAL(severity_level::debug) << "test";
	BOOST_LOG_TRIVIAL(severity_level::warning) << "test";
	BOOST_LOG_TRIVIAL(severity_level::error) << "test";
	BOOST_LOG_TRIVIAL(severity_level::fatal) << "test";

	system("pause");
	return 0;
}
