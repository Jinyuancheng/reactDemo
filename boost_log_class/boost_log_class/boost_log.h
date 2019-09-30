#pragma once
#ifndef _CBOOSTLOG_H_
#define _CBOOSTLOG_H_
#include <iostream>
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

class CBoostLog
{
public:
	CBoostLog();
	~CBoostLog();
public:
	/*\ �õ�CBoostLog���� \*/
	static CBoostLog* GetInstance();
	/*\ �ͷ�CBoostLog���� \*/
	static void DelInstance();
	/*\ ��ʼ�� \*/
	void Init(std::string _filename);
	/*\ д��־ \*/
	void WriteLog(severity_level _serverity, std::string _msg);
private:

	static CBoostLog* m_instance;
};

#endif


