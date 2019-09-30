#pragma once
#ifndef _MYSQL_OPT_H_
#define _MYSQL_OPT_H_
#include <mysql/mysql.h>
#ifndef _IOSTREAM_
#include <iostream>
#endif
namespace MySqlOpt
{
	class CMySql
	{
	public:
		CMySql();
		~CMySql();
	public:
		/*\ 创建数据库连接 \*/
		bool mysql_create_conn(std::string& _ip, std::string& _user, std::string& _pass, std::string& _database);
		/*\ 插入数据 \*/
		bool mysql_insert(std::string& _sql);
		/*\ 更新数据 \*/
		bool mysql_update(std::string& _sql);
		/*\ 查询数据 \*/
		bool mysql_select(std::string& _sql);
		/*\ 删除数据 \*/
		bool mysql_delete(std::string& _sql);
		/*\ 得到查询的数据 \*/
		MYSQL_RES* get_select_result();
	private:
		MYSQL*				m_oMysql;			/*\ 操作数据库的连接 \*/
		MYSQL_RES*			m_oMysqlRes;		/*\ 查询mysql数据库的结果 \*/
		std::string			m_sDataBaseIp;		/*\ 数据库的ip \*/
		std::string			m_sDataBaseName;	/*\ 数据库名称 \*/
	};
}
#endif // !_MYSQL_OPT_H_
