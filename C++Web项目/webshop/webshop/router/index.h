#pragma once
#ifndef _INDEX_H_
#define _INDEX_H_

#include "../include/cinatra.hpp"
using namespace cinatra;

cinatra::http_server* gl_CHttpServer = NULL;

int LoadRouter()
{
	gl_CHttpServer->set_http_handler<GET, POST>("/jinzi", [](request& req, response& res) {
		res.render_string("Success");
	}, enable_cache{ false });
	return 0;
}

void SetHttpServer(cinatra::http_server* _HttpServer)
{
	gl_CHttpServer = _HttpServer;
	LoadRouter();
}



#endif