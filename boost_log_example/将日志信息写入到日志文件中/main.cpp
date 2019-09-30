/**************************************************************
 * @file main.cpp
 * @date 2019/08/21 16:13
 * @author Jinzi
 * @Contact: 2493349541@qq.com
 * @brief 演示将日志信息写入到日志文件中(.log)
***************************************************************/
#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/common.hpp>
#include <boost/log/exceptions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

using namespace std;

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

int main(int argc, char *argv[])
{
	//设置存储日志文件信息
	logging::add_file_log(
		keywords::file_name = "jinzi.log",			/*\ 日志文件名称 \*/
		keywords::rotation_size = 10 * 1024 * 1024	/*\ 日志文件的大小 \*/
	);
	/*\ 设置过滤器 \*/
	logging::core::get()->set_filter(
		logging::trivial::severity >= logging::trivial::severity_level::info
	);
	/*\ 将日志信息和过滤器存储到公共属性中 \*/
	logging::add_common_attributes();

	using namespace logging::trivial;
	src::severity_logger<severity_level> lg;

	BOOST_LOG_SEV(lg, trace) << "A trace severity message";
	BOOST_LOG_SEV(lg, debug) << "A debug severity message";
	BOOST_LOG_SEV(lg, info) << "An informational severity message";
	BOOST_LOG_SEV(lg, warning) << "A warning severity message";
	BOOST_LOG_SEV(lg, error) << "An error severity message";
	BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";

	system("pause");
	return 0;
}
