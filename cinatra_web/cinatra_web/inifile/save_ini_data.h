#pragma once
#ifndef _SAVE_INI_DATA_
#define _SAVE_INI_DATA_
#ifndef _TEMPLATE_H_
#include "../template/template.h"
#endif // !_TEMPLATE_H_
#include <iostream>
#include <vector>
#include <map>
//�������ļ����в���
namespace INIFILE
{
	/*\ �洢��ȡini�ļ������� \*/
	class CSaveIniData : public CSingleton<CSaveIniData>
	{
	public:
		/*\ ��ȡini�ļ� \*/
		void ReadIniFile(const char* filename);	
		/*\ �õ������ļ��ж˿���Ϣ \*/
		std::map<std::string, std::string> GetPortInfo();
		/*\ �õ������ļ���mysql��������Ϣ \*/
		std::map<std::string, std::string> GetMySqlInfo();
	private:
		std::map<std::string, std::string>		m_mapPort;	/*\ �����洢�˿ڵ���Ϣ \*/
		std::map<std::string, std::string>		m_mapMySql;	/*\ �洢mysql������Ϣ \*/
	};
}

#endif



