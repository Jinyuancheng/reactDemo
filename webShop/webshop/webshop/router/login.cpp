#ifndef _LOGIN_H_
#include "./login.h"
#endif

#ifndef _JINZIUTILS_H_
#include "../utils/utils.h"
#endif

//************************************     
// 函数名称: Login   
// 函数说明: Login类的构造函数 用来初始化数据    
// 作 成 者: 金子     
// 作成日期: 2019/04/17 22:20:05  
// 返 回 值:      
// 参    数:   
//************************************  
nsLogin::Login::Login()
{
	this->m_CHttpServer = NULL;
}
//************************************     
// 函数名称: LoadLoginRouter   
// 函数说明: 加载路由等    
// 作 成 者: 金子     
// 作成日期: 2019/04/17 21:55:01  
// 返 回 值:      
// 参    数:   
//************************************  
int nsLogin::Login::LoadLoginRouter()
{
	/*\ 用来处理用户登录的路由 */
	this->m_CHttpServer->set_http_handler<GET, POST, OPTIONS>("/login", [](request& req, response& res) {
		nsLogin::Login::UserLogin(req, res);
	}, enable_cache{ false });
	/*\ 用来处理用户注册的路由 */
	this->m_CHttpServer->set_http_handler<GET, POST>("/regist", [](request& req, response& res) {
		nsLogin::Login::UserRegist(req, res);
	}, enable_cache{ false });
	return 0;
}
//************************************     
// 函数名称: SetHttpServer   
// 函数说明: 用来将服务器的指针句柄传入到该文件中    
// 作 成 者: 金子     
// 作成日期: 2019/04/17 21:53:08     
// 返 回 值:      
// 参    数:   _HttpServer 服务器句柄的指针
//************************************  
void nsLogin::Login::SetHttpServer(cinatra::http_server* _HttpServer)
{
	this->m_CHttpServer = _HttpServer;
	Login::LoadLoginRouter();
}
//************************************     
// 函数名称: UserLogin   
// 函数说明: 用户登录的方法    
// 作 成 者: 金子     
// 作成日期: 2019/04/17 22:23:53  
// 返 回 值:      
// 参    数:   req 请求数据对象 res 响应数据对象
//************************************  
void nsLogin::Login::UserLogin(request& req, response& res)
{
	auto Data = req.body();
	if (Data.empty())
	{
		res.render_string("请求参数为空");
	}
	else
	{
		printf("Req.body = %s\n", req.body().data());
		std::vector<std::string> vecData = JinziUtils::GetInstance()->UtilsUrlToSerialize((std::string)Data);
		std::string username = JinziUtils::GetInstance()->UtilsStringWithInString(vecData, "username");
		std::string password = JinziUtils::GetInstance()->UtilsStringWithInString(vecData, "password");
		nlohmann::json json;
		if (username == "jinzi" && password == "111111")
		{
			json["result"] = "0";
			json["msg"] = "用户登录成功";
			res.render_json(json);
		}
		else
		{
			json["result"] = "-1";
			json["msg"] = "用户登录失败";
			res.render_json(json);
		}
	}
	
}
//************************************     
// 函数名称: UserRegist   
// 函数说明: 用户注册    
// 作 成 者: 金子     
// 作成日期: 2019/04/17 22:36:06  
// 返 回 值:      
// 参    数:   req 请求数据对象 res 响应数据对象
//************************************  
void nsLogin::Login::UserRegist(request& req, response& res)
{
	res.render_string("Regist Success");
}