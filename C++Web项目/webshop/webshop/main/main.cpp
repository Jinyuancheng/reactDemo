#include <iostream>

#include "../include/cinatra.hpp"

#ifndef _INDEX_H_
#include "../router/index.h"
#endif

using namespace cinatra;
using namespace std;

std::string gl_strPort = "10086";		/*\ 服务器监听端口 \*/
const int gl_iMaxThreadNum = 4;			/*\ 开启的最大线程数 \*/

http_server* server = new http_server(gl_iMaxThreadNum);
int main()
{
	bool r = server->listen("0.0.0.0", gl_strPort);
	if (!r) {
		//LOG_INFO << "listen failed";
		return -1;
	}
	else
	{
		cout << "Server Listen Port : " << gl_strPort << endl;
	}
	server->set_http_handler<GET, POST>("/", [](request& req, response& res) {
		res.set_status_and_content(status_type::ok, "hello world");
	}, enable_cache{ false });
	SetHttpServer(server);
	server->set_http_handler<GET, POST>("/jinzi1", [](request& req, response& res) {
		res.render_string("Success");
	}, enable_cache{ false });
	server->run();
	return 0;
}
