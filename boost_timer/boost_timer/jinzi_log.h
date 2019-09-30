/**********************************************************************
* Copyright (C) 2019-2020 天津白泽技术有限公司
* 文件名: jinzi_log
* 描述: 日志文件
**********************************************************************/
#pragma once
#ifndef _jinzi_log_h
#define _jinzi_log_h

#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

using boost::shared_ptr;

enum severity_level
{
	normal,
	notification,
	warning,
	error,
	critical
};
namespace jinzi
{
	/*\ 输出日志类 \*/
	class CLog
	{
	public:
		CLog() {};
		CLog(std::string _FileName);
		~CLog() {};
	public:
		/*\ 基础写日志的函数 \*/
		void BaseWriteLog(std::string _FileName, 
			severity_level _ServLevl, std::string _WriteData);
	private:
		src::severity_logger< severity_level >	m_Slog;	/*\ 操作文件的句柄 \*/
		src::logger								m_Log;	/*\ 用来操作日志的句柄 \*/
	};
};
#endif


