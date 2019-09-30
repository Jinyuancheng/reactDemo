#include "save_ini_data.h"
#include <boost/property_tree/ptree.hpp>  
#include <boost/property_tree/ini_parser.hpp>
#include "../utils/utils.h"
#include <string.h>
/****************************************!
*@brief  ��ȡ�����ļ�
*@author Jinzi
*@date   2019/06/20 15:04:34
*@param[in]  filename �����ļ���ȫ·��
			 _inifile ȫ�ֵ������ļ�����
*@param[out]
*@return    �ɹ�����0 ʧ�ܷ���-1
****************************************/
void INIFILE::CSaveIniData::ReadIniFile(const char* filename)	//��ȡini�ļ�
{
	int iRet = -1;
	std::string sPort;
	boost::property_tree::ptree oPtree, tag_setting;
	read_ini(filename, oPtree);
	///////////////////// 2019/06/24 13:15:35 ��ȡ�˿����� ==> BEGIN /////////////////////////////////////////////////////
	tag_setting = oPtree.get_child("SERVER_PORT");
	sPort = tag_setting.get<std::string>("main_port", "10086");
	this->m_mapPort.insert(pair<std::string, std::string>("main_port", sPort));
	sPort = tag_setting.get<std::string>("user_port", "10087");
	this->m_mapPort.insert(pair<std::string, std::string>("user_port", sPort));
	sPort = tag_setting.get<std::string>("manage_port", "10088");
	this->m_mapPort.insert(pair<std::string, std::string>("manage_port", sPort));
	///////////////////// 2019/06/24 13:15:35 ��ȡ�˿����� ==> END /////////////////////////////////////////////////////

	///////////////////// 2019/06/24 13:15:54 ��ȡmysql���� ==> BEGIN /////////////////////////////////////////////////////
	tag_setting = oPtree.get_child("MYSQL");
	sPort = tag_setting.get<std::string>("mysql_ip", "localhost");
	this->m_mapMySql.insert(pair<std::string, std::string>("mysql_ip", sPort));
	sPort = tag_setting.get<std::string>("mysql_user", "root");
	this->m_mapMySql.insert(pair<std::string, std::string>("mysql_user", sPort));
	sPort = tag_setting.get<std::string>("mysql_pass", "Kanshenme0113@qq.com");
	this->m_mapMySql.insert(pair<std::string, std::string>("mysql_pass", sPort));
	sPort = tag_setting.get<std::string>("mysql_database", "jbl_shop");
	this->m_mapMySql.insert(pair<std::string, std::string>("mysql_database", sPort));
	///////////////////// 2019/06/24 13:15:54 ��ȡmysql���� ==> END /////////////////////////////////////////////////////
}
/****************************************!
*@brief  �õ������ļ��еĶ˿���Ϣ
*@author Jinzi
*@date   2019/06/20 15:55:00
*@param[in]
*@param[out]
*@return     ����һ��map�������ͣ�map<string,string>��1.��Ӧ�����ļ��е�keyֵ��2.��Ӧvalue
****************************************/
std::map<std::string, std::string> INIFILE::CSaveIniData::GetPortInfo()
{
	return this->m_mapPort;
}
 /****************************************!
 *@brief  �õ������ļ��е�mysql ������Ϣ
 *@author Jinzi
 *@date   2019/06/24 13:18:33
 *@param[in]  
 *@param[out] 
 *@return     ����һ��map�������ͣ�map<string,string>��1.��Ӧ�����ļ��е�keyֵ��2.��Ӧvalue
 ****************************************/
std::map<std::string, std::string> INIFILE::CSaveIniData::GetMySqlInfo()
{
	return this->m_mapMySql;
}