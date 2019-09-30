#include <iostream>

#ifndef CINATRA_CINATRA_HPP
#include "../include/cinatra.hpp"
using namespace cinatra;
#endif

#ifndef _LOGIN_H_
#include "../router/login.h"
#endif

using namespace std;

std::string gl_strPort = "10086";		/*\ 服务器监听端口 \*/
const int gl_iMaxThreadNum = 4;			/*\ 开启的最大线程数 \*/

http_server gl_Server(gl_iMaxThreadNum);
int main()
{
	bool r = gl_Server.listen("0.0.0.0", gl_strPort);
	if (!r) {
		cout << "Server Start Error" << endl;
		return -1;
	}
	else
	{
		cout << "Server Listen Port : " << gl_strPort << endl;
	}
	gl_Server.set_base_path("base_path", "/feather");
	gl_Server.enable_http_cache(false);//set global cache
	gl_Server.set_res_cache_max_age(86400);
	gl_Server.set_cache_max_age(5);
	/*\ 将服务器的句柄传入到子文件中 */
	nsLogin::Login login;
	login.SetHttpServer(&gl_Server);
	gl_Server.run();
	return 0;
}
