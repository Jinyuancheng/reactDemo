#include "./mysql_opt.h"
 /****************************************!
 *@brief  ���캯������ʼ��MYSQL�ṹ��
 *@author Jinzi
 *@date   2019/06/24 11:37:31
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
MySqlOpt::CMySql::CMySql()
{
	this->m_oMysql = new MYSQL();
	this->m_oMysqlRes = new MYSQL_RES();
	mysql_init(this->m_oMysql);
}
 /****************************************!
 *@brief  �������� �ͷ�
 *@author Jinzi
 *@date   2019/06/24 12:06:02
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
MySqlOpt::CMySql::~CMySql()
{
	mysql_close(this->m_oMysql);
	delete[] this->m_oMysql;
	delete[] this->m_oMysqlRes;
}
 /****************************************!
 *@brief  �������ݿ�����
 *@author Jinzi
 *@date   2019/06/24 11:55:50
 *@param[in]  _ip ���ݿ�IP ����Ǳ���ֱ�Ӵ���localhost
			  _user ���ݿ��û��� root
			  _pass ���ݿ����� Kanshenme0113@qq.com
			  _database ���ݿ� test
 *@param[out] 
 *@return     �ɹ����� true ʧ�ܷ���false
 ****************************************/
bool MySqlOpt::CMySql::mysql_create_conn(std::string& _ip, std::string& _user, std::string& _pass, std::string& _database)
{
	bool bRet = true;
	this->m_sDataBaseIp = _ip;
	this->m_sDataBaseName = _database;
	if (!mysql_real_connect(this->m_oMysql, _ip.c_str(), _user.c_str(), _pass.c_str(), _database.c_str(), 0, NULL, 0))
	{
		std::cout << "Create Mysql Connect Error" << std::endl;
		bRet = false;
	}
	std::cout << "Create Mysql Connect Success" << std::endl;
	return bRet;
}
 /****************************************!
 *@brief  ����MySql���ݿ����
 *@author Jinzi
 *@date   2019/06/24 12:01:34
 *@param[in]  _sql �����sql���
 *@param[out] 
 *@return     
 ****************************************/
bool MySqlOpt::CMySql::mysql_insert(std::string& _sql)
{
	bool bRet = false;
	if (mysql_query(this->m_oMysql, _sql.c_str()) >= 0)
	{
		bRet = true;
	}
	return bRet;
}
 /****************************************!
 *@brief  �������ݿ�
 *@author Jinzi
 *@date   2019/06/24 12:09:24
 *@param[in]  _sql �������ݿ�����
 *@param[out] 
 *@return     
 ****************************************/
bool MySqlOpt::CMySql::mysql_update(std::string& _sql)
{
	bool bRet = false;
	if (mysql_query(this->m_oMysql, _sql.c_str()) >= 0)
	{
		bRet = true;
	}
	return bRet;
}
 /****************************************!
 *@brief  ��ѯmysql���ݿ�
 *@author Jinzi
 *@date   2019/06/24 12:11:35
 *@param[in]  _sql��ѯ���ݿ����
 *@param[out] 
 *@return     
 ****************************************/
bool MySqlOpt::CMySql::mysql_select(std::string& _sql)
{
	bool bRet = true;
	if (!(mysql_query(m_oMysql, _sql.c_str()) >= 0))
	{
		bRet = false;
		return bRet;
	}
	this->m_oMysqlRes = mysql_store_result(this->m_oMysql);
	return bRet;
}
 /****************************************!
 *@brief  ɾ������
 *@author Jinzi
 *@date   2019/06/24 12:58:14
 *@param[in]  _sql ɾ������sql���
 *@param[out] 
 *@return     
 ****************************************/
bool MySqlOpt::CMySql::mysql_delete(std::string& _sql)
{
	bool bRet = false;
	if (mysql_query(this->m_oMysql, _sql.c_str()) >= 0)
	{
		bRet = true;
	}
	return bRet;
}
/*\ �õ���ѯ���ݿ�Ľ�� \*/
MYSQL_RES* MySqlOpt::CMySql::get_select_result()
{
	return this->m_oMysqlRes;
}