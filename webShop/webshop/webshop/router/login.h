#pragma once
#ifndef _LOGIN_H_
#define _LOGIN_H_

#ifndef CINATRA_CINATRA_HPP
#include "../include/cinatra.hpp"
using namespace cinatra;
#endif

/*\ �û���¼�������ռ� */
namespace nsLogin 
{
	/*\ ��¼���� */
	class Login
	{
	public :
		Login();
	public:
		/*\ ���ص�¼��·�� */
		int LoadLoginRouter();
		/*\ ����http��������ָ���� */
		void SetHttpServer(cinatra::http_server* _HttpServer);
		/*\ �û���¼ */
		static void UserLogin(request& req, response& res);
		/*\ �û�ע�� */
		static void UserRegist(request& req, response& res);
	private:
		cinatra::http_server* m_CHttpServer;			/*\ server�������ľ�� */
	};
}
#endif