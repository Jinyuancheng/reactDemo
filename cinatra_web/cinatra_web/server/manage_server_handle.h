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
	/*\ �����߳̿�����̨��������� \*/
	void ThreadRun();
	/*\ ��̨��������� \*/
	class CBackstageManage
	{
	public:
		CBackstageManage(std::string _port);
		~CBackstageManage();
	public:
		/*\ �ж����ĸ�·�� \*/
		void manage_server_router();
		/*\ ���з����� \*/
		void manage_server_run();
		/*\ ��ѯ�û���Ϣ \*/
		void manage_select_userinfo(cinatra::request& req, cinatra::response& res);
	private:
		std::string							m_sPort;			/*\ �����������˿� \*/
	};
}


#endif



