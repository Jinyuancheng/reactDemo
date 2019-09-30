#include "./jinzi_log.h"

#include <iostream>
#include <fstream>
using namespace std;
/****************************************!
*@brief  ������д�ļ���־�ĺ���
*@author Jinzi
*@date   2019/06/11 15:29:49
*@param[in]  _FileName  �ļ�����
			 _ServLevl  ��־�ĵȼ�
			 _WriteData �洢����־�ľ�����Ϣ
*@param[out]
*@return	
****************************************/
void jinzi::CLog::BaseWriteLog(std::string _FileName, severity_level _ServLevl, std::string _WriteData)
{
	BOOST_LOG_SEV(this->m_Slog, _ServLevl) << _WriteData;
}
 /****************************************!
 *@brief  ���캯����ʼ������
 *@author Jinzi
 *@date   2019/06/11 15:42:37
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
jinzi::CLog::CLog(std::string _FileName)
{
	logging::add_file_log
	(
		_FileName,
		keywords::format = expr::format("%1% [%2%] [%3%] <%4%> %5%")
		% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
		% expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
		% expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
		% expr::attr< severity_level >("Severity")
		% expr::message
	);
	logging::add_common_attributes();
	logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());
	BOOST_LOG_FUNCTION();
	//src::severity_logger< severity_level > slg;
	this->m_Slog.add_attribute("Uptime", attrs::timer());
	//slg.add_attribute("Uptime", attrs::timer());
}