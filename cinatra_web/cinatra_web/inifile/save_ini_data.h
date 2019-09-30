#pragma once
#ifndef _SAVE_INI_DATA_
#define _SAVE_INI_DATA_
#ifndef _TEMPLATE_H_
#include "../template/template.h"
#endif // !_TEMPLATE_H_
#include <iostream>
#include <vector>
#include <map>
//对配置文件进行操作
namespace INIFILE
{
	/*\ 存储读取ini文件的数据 \*/
	class CSaveIniData : public CSingleton<CSaveIniData>
	{
	public:
		/*\ 读取ini文件 \*/
		void ReadIniFile(const char* filename);	
		/*\ 得到配置文件中端口信息 \*/
		std::map<std::string, std::string> GetPortInfo();
		/*\ 得到配置文件中mysql的配置信息 \*/
		std::map<std::string, std::string> GetMySqlInfo();
	private:
		std::map<std::string, std::string>		m_mapPort;	/*\ 用来存储端口的信息 \*/
		std::map<std::string, std::string>		m_mapMySql;	/*\ 存储mysql数据信息 \*/
	};
}

#endif



