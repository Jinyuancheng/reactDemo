#include "user_server_handle.h"
#include <boost/thread/thread.hpp>
#include <iostream>
http_server gl_user_server(4);
#ifndef _SERVER_ROUTER_H_
#include "../router/router.h"
#endif
#ifndef _SAVE_INI_DATA_
#include "../inifile/save_ini_data.h"
#endif
#include <map>

/****************************************!
*@brief  CUserServerHandle构造函数
*@author Jinzi
*@date   2019/06/20 13:56:12
*@param[in]  
*@param[out]
*@return
****************************************/
UserServer::CUserServerHandle::CUserServerHandle(std::string _port, INIFILE::CSaveIniData& _inifile)
{
	/*std::map<std::string, std::string> mapMySql;
	std::map<std::string, std::string>::iterator itMySqlIp;
	std::map<std::string, std::string>::iterator itMySqlUser;
	std::map<std::string, std::string>::iterator itMySqlPass;
	std::map<std::string, std::string>::iterator itMySqlDatabase;
	this->m_oIniFileData = _inifile;
	mapMySql = this->m_oIniFileData.GetMySqlInfo();
	itMySqlIp = mapMySql.find("mysql_ip");
	itMySqlUser = mapMySql.find("user_ip");
	itMySqlPass = mapMySql.find("pass_ip");
	itMySqlDatabase = mapMySql.find("database_ip");
	this->m_oMySql = new MySqlOpt::CMySql();
	this->m_oMySql->mysql_create_conn(itMySqlIp->second, itMySqlUser->second,
		itMySqlPass->second, itMySqlDatabase->second);*/
	this->m_sPort = _port;
	bool iRet = gl_user_server.listen("0.0.0.0", static_cast<std::string>(_port));
	if (!iRet)
	{
		std::cout << "UserServer Listen Port : " << _port << " Failed" << std::endl;
	}
	gl_user_server.set_base_path("base_path", "/feather");
	gl_user_server.enable_http_cache(false);//set global cache
	gl_user_server.set_res_cache_max_age(86400);
	gl_user_server.set_cache_max_age(5);
}
 /****************************************!
 *@brief  开启服务器
 *@author Jinzi
 *@date   2019/06/20 14:04:50
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_server_run()
{
	std::cout << "UserServer Listen Port : " << this->m_sPort << std::endl;
	boost::thread thread(ThreadRun);
}
 /****************************************!
 *@brief  析构函数
 *@author Jinzi
 *@date   2019/06/20 14:06:36
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
UserServer::CUserServerHandle::~CUserServerHandle()
{
	//delete[] this->m_oMySql;
}
 /****************************************!
 *@brief  启动线程开启服务
 *@author Jinzi
 *@date   2019/06/20 16:19:17
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::ThreadRun()
{
	gl_user_server.run();
}

/*\ 判断是哪个路由 \*/
void UserServer::CUserServerHandle::user_server_router()
{
	/*\ 用来处理用户登录的路由 */
	gl_user_server.set_http_handler<GET, POST>(USER_SERVER_LOGIN, [=](cinatra::request& req, cinatra::response& res) {
		this->user_login(req, res);
	});
	/*\ 用来处理用户注册的路由 */
	gl_user_server.set_http_handler<GET, POST>(USER_SERVER_REGIST, [=](cinatra::request& req, cinatra::response& res) {
		this->user_regist(req, res);
	});
	/*\ 用户微信登录 \*/
	gl_user_server.set_http_handler<GET, POST>(USER_SERVER_WXLOGIN, [=](cinatra::request& req, cinatra::response& res) {
		this->user_wx_login(req, res);
	});
	/*\ 用户qq登录 \*/
	gl_user_server.set_http_handler<GET, POST>(USER_SERVER_QQLOGIN, [=](cinatra::request& req, cinatra::response& res) {
		this->user_qq_login(req, res);
	});
	/*\ 用户手机号登录 \*/
	gl_user_server.set_http_handler<GET, POST>(USER_SERVER_PHONELOGIN, [=](cinatra::request& req, cinatra::response& res) {
		this->user_phone_login(req, res);
	});
	/*\ 后台管理登录 \*/
	gl_user_server.set_http_handler<GET, POST>(USER_SERVER_MANAGELOGIN, [=](cinatra::request& req, cinatra::response& res) {
		this->user_mange_login(req, res);
	});
}
