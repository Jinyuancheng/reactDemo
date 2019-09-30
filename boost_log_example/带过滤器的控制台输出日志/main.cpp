/**************************************************************
 * @file main.cpp
 * @date 2019/08/21 15:54
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief ��ʾ���й������Ŀ���̨�����־
***************************************************************/
#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
using namespace std;

namespace logging = boost::log;

int main(int argc, char *argv[])
{
	/*\ ����ȫ�ֵĹ�������get()�����õ����ĵĵ���ģʽ��һ�����������������в��� \*/
	logging::core::get()->set_filter(
		/*\ ���ù������ȼ� \*/
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
