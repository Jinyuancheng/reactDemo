#pragma once
#ifndef _BACKSTAGEMANAGE_H_
#define _BACKSTAGEMANAGE_H_
#include <memory>
#ifndef CINATRA_CINATRA_HPP
#include "../include/cinatra.hpp"
using namespace cinatra;
#endif

namespace ManageServer
{
	/*\ 开启线程开启后台管理服务器 \*/
	void ThreadRun();
	/*\ 后台管理服务器 \*/
	class CBackstageManage
	{
	public:
		CBackstageManage(std::string _port);
		~CBackstageManage();
	public:
		/*\ 判断是哪个路由 \*/
		void manage_server_router();
		/*\ 运行服务器 \*/
		void manage_server_run();
		/*\ 查询用户信息 \*/
		void manage_select_userinfo(cinatra::request& req, cinatra::response& res);
	private:
		std::string							m_sPort;			/*\ 服务器监听端口 \*/
	};
}


#endif



