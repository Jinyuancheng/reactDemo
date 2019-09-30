
#include "boost_log.h"

CBoostLog* CBoostLog::m_instance = CBoostLog::GetInstance();
 /****************************************!
 *@brief  构造函数
 *@author Jinzi
 *@date   2019/07/24 16:01:21
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
CBoostLog::CBoostLog()
{
	
}
 /****************************************!
 *@brief  写入日志
 *@author Jinzi
 *@date   2019/07/24 16:01:53
 *@param[in]  _serverity 级别
			  _msg 内容
 *@param[out] 
 *@return     
 ****************************************/
void CBoostLog::WriteLog(severity_level _serverity, std::string _msg)
{
	/*\ 用来写入日志 \*/
	src::severity_logger< severity_level > m_oSeverityLog;
	m_oSeverityLog.add_attribute("Uptime", attrs::timer());
	BOOST_LOG_SEV(m_oSeverityLog, _serverity) << _msg.c_str();
}
 /****************************************!
 *@brief  初始化信息
 *@author Jinzi
 *@date   2019/07/24 16:07:00
 *@param[in]  _filename 日志文件名
 *@param[out] 
 *@return     
 ****************************************/
void CBoostLog::Init(std::string _filename)
{
	logging::add_console_log(std::clog, keywords::format = "%TimeStamp%: %Message%");
	logging::add_file_log
	(
		_filename,
		keywords::filter = expr::attr< severity_level >("Severity") >= normal,
		keywords::format = expr::format("[%1%] [%2%] [%3%] <%4%> %5%")
		% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
		% expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
		% expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
		% expr::attr< severity_level >("Severity")
		% expr::message
	);
	logging::add_common_attributes();
	logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());
	BOOST_LOG_FUNCTION();
}
 /****************************************!
 *@brief  得到一个CBoostLog对象
 *@author Jinzi
 *@date   2019/07/24 16:08:21
 *@param[in]  
 *@param[out] 
 *@return     CBoostLog*
 ****************************************/
CBoostLog* CBoostLog::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new CBoostLog();
	}
	return m_instance;
}
 /****************************************!
 *@brief  释放CBoostLog对象
 *@author Jinzi
 *@date   2019/07/24 16:09:37
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void CBoostLog::DelInstance()
{
	if (m_instance)
	{
		delete[] m_instance;
		m_instance = nullptr;
	}
}
CBoostLog::~CBoostLog()
{
}
