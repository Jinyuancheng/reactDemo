#include "./mysql_opt.h"
 /****************************************!
 *@brief  构造函数，初始化MYSQL结构体
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
 *@brief  析构函数 释放
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
 *@brief  创建数据库连接
 *@author Jinzi
 *@date   2019/06/24 11:55:50
 *@param[in]  _ip 数据库IP 如果是本地直接传入localhost
			  _user 数据库用户名 root
			  _pass 数据库密码 Kanshenme0113@qq.com
			  _database 数据库 test
 *@param[out] 
 *@return     成功返回 true 失败返回false
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
 *@brief  插入MySql数据库操作
 *@author Jinzi
 *@date   2019/06/24 12:01:34
 *@param[in]  _sql 插入的sql语句
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
 *@brief  更新数据库
 *@author Jinzi
 *@date   2019/06/24 12:09:24
 *@param[in]  _sql 更新数据库的语句
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
 *@brief  查询mysql数据库
 *@author Jinzi
 *@date   2019/06/24 12:11:35
 *@param[in]  _sql查询数据库语句
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
 *@brief  删除数据
 *@author Jinzi
 *@date   2019/06/24 12:58:14
 *@param[in]  _sql 删除数据sql语句
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
/*\ 得到查询数据库的结果 \*/
MYSQL_RES* MySqlOpt::CMySql::get_select_result()
{
	return this->m_oMysqlRes;
}