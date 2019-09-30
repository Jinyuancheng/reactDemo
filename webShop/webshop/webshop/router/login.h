#pragma once
#ifndef _LOGIN_H_
#define _LOGIN_H_

#ifndef CINATRA_CINATRA_HPP
#include "../include/cinatra.hpp"
using namespace cinatra;
#endif

/*\ 用户登录的命名空间 */
namespace nsLogin 
{
	/*\ 登录的类 */
	class Login
	{
	public :
		Login();
	public:
		/*\ 加载登录的路由 */
		int LoadLoginRouter();
		/*\ 设置http服务器的指针句柄 */
		void SetHttpServer(cinatra::http_server* _HttpServer);
		/*\ 用户登录 */
		static void UserLogin(request& req, response& res);
		/*\ 用户注册 */
		static void UserRegist(request& req, response& res);
	private:
		cinatra::http_server* m_CHttpServer;			/*\ server服务器的句柄 */
	};
}
#endif