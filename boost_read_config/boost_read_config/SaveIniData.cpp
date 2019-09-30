#include "SaveIniData.h"
#include "boost/lexical_cast.hpp"
using namespace boost;
CSaveIniData::CSaveIniData(std::string& filename)
{
	///////////////////// 2019/07/08 14:51:57 SERVER ==> BEGIN /////////////////////////////////////////////////////
	read_ini(filename, this->m_oParent);
	this->m_oChild = this->m_oParent.get_child("SERVER");
	this->m_oServerConfig.Ip = this->m_oChild.get <std::string>("ip");
	this->m_oServerConfig.port = this->m_oChild.get<std::string>("port");
	///////////////////// 2019/07/08 14:51:57 SERVER ==> END/////////////////////////////////////////////////////
	
	///////////////////// 2019/07/08 14:53:03 MYSQL ==> BEGIN /////////////////////////////////////////////////////
	this->m_oChild = this->m_oParent.get_child("MYSQL");
	this->m_oMysqlConfig.host = this->m_oChild.get<std::string>("host");
	this->m_oMysqlConfig.user = this->m_oChild.get<std::string>("user");
	this->m_oMysqlConfig.pass = this->m_oChild.get<std::string>("pass");
	this->m_oMysqlConfig.database = this->m_oChild.get<std::string>("database");
	///////////////////// 2019/07/08 14:53:03 MYSQL ==> END /////////////////////////////////////////////////////
}
CSaveIniData::~CSaveIniData()
{

}
Stru_MysqlConfig CSaveIniData::GetMysqlConfig()
{
	return this->m_oMysqlConfig;
}
Stru_ServerConfig CSaveIniData::GetServerConfig()
{
	return this->m_oServerConfig;
}

std::string CSaveIniData::toString()
{
	return lexical_cast<std::string>("jinzi", 3);
}