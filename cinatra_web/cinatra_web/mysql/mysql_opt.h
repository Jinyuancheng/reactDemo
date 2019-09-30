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
		/*\ �������ݿ����� \*/
		bool mysql_create_conn(std::string& _ip, std::string& _user, std::string& _pass, std::string& _database);
		/*\ �������� \*/
		bool mysql_insert(std::string& _sql);
		/*\ �������� \*/
		bool mysql_update(std::string& _sql);
		/*\ ��ѯ���� \*/
		bool mysql_select(std::string& _sql);
		/*\ ɾ������ \*/
		bool mysql_delete(std::string& _sql);
		/*\ �õ���ѯ������ \*/
		MYSQL_RES* get_select_result();
	private:
		MYSQL*				m_oMysql;			/*\ �������ݿ������ \*/
		MYSQL_RES*			m_oMysqlRes;		/*\ ��ѯmysql���ݿ�Ľ�� \*/
		std::string			m_sDataBaseIp;		/*\ ���ݿ��ip \*/
		std::string			m_sDataBaseName;	/*\ ���ݿ����� \*/
	};
}
#endif // !_MYSQL_OPT_H_
