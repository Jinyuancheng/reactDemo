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
//用户操作的服务器
namespace UserServer
{
	/*\ 使用线程开启服务器 \*/
	void ThreadRun();
	/*\ 用户服务器 \*/
	class CUserServerHandle
	{
	public:
		CUserServerHandle(std::string _port, INIFILE::CSaveIniData& _inifile);
		~CUserServerHandle();
	public:
		/*\ 判断是哪个路由 \*/
		void user_server_router();
		/*\ 运行服务器 \*/
		void user_server_run();
		/*\ 用户登录 \*/
		void user_login(cinatra::request& req, cinatra::response& res);
		/*\ 用户微信登录 \*/
		void user_wx_login(cinatra::request& req, cinatra::response& res);
		/*\ 用户qq登录 \*/
		void user_qq_login(cinatra::request& req, cinatra::response& res);
		/*\ 用户手机号登录 \*/
		void user_phone_login(cinatra::request& req, cinatra::response& res);
		/*\ 后台管理登录 \*/
		void user_mange_login(cinatra::request& req, cinatra::response& res);
		/*\ 用户注册 \*/
		void user_regist(cinatra::request& req, cinatra::response& res);
	private:
		std::string							m_sPort;			/*\ 服务器监听端口 \*/
		//MySqlOpt::CMySql*					m_oMySql;			/*\ 用来操作数据库的连接 \*/
		INIFILE::CSaveIniData				m_oIniFileData;		/*\ 用来操作存储配置文件信息 \*/
	};
}
#endif


