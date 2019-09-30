#pragma once
#ifndef USER_SERVER_H
#define USER_SERVER_H
#include <memory>
#ifndef CINATRA_CINATRA_HPP
#include "../include/cinatra.hpp"
using namespace cinatra;
#endif
#ifndef _MYSQL_OPT_H_
#include "../mysql/mysql_opt.h"
#endif
#ifndef _SAVE_INI_DATA_
#include "../inifile/save_ini_data.h"
#endif
//�û������ķ�����
namespace UserServer
{
	/*\ ʹ���߳̿��������� \*/
	void ThreadRun();
	/*\ �û������� \*/
	class CUserServerHandle
	{
	public:
		CUserServerHandle(std::string _port, INIFILE::CSaveIniData& _inifile);
		~CUserServerHandle();
	public:
		/*\ �ж����ĸ�·�� \*/
		void user_server_router();
		/*\ ���з����� \*/
		void user_server_run();
		/*\ �û���¼ \*/
		void user_login(cinatra::request& req, cinatra::response& res);
		/*\ �û�΢�ŵ�¼ \*/
		void user_wx_login(cinatra::request& req, cinatra::response& res);
		/*\ �û�qq��¼ \*/
		void user_qq_login(cinatra::request& req, cinatra::response& res);
		/*\ �û��ֻ��ŵ�¼ \*/
		void user_phone_login(cinatra::request& req, cinatra::response& res);
		/*\ ��̨�����¼ \*/
		void user_mange_login(cinatra::request& req, cinatra::response& res);
		/*\ �û�ע�� \*/
		void user_regist(cinatra::request& req, cinatra::response& res);
	private:
		std::string							m_sPort;			/*\ �����������˿� \*/
		//MySqlOpt::CMySql*					m_oMySql;			/*\ �����������ݿ������ \*/
		INIFILE::CSaveIniData				m_oIniFileData;		/*\ ���������洢�����ļ���Ϣ \*/
	};
}
#endif


