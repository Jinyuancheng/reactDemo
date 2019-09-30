#include <iostream>
#include <map>
#ifndef CINATRA_CINATRA_HPP
#include "./include/cinatra.hpp"
#endif
#ifndef USER_SERVER_H
#include "./server/user_server_handle.h"
#endif
#ifndef _SAVE_INI_DATA_
#include "./inifile/save_ini_data.h"
#endif
#ifndef _JINZIUTILS_H_
#include "./utils/utils.h"
#endif // !_JINZIUTILS_H_
#ifndef _BACKSTAGEMANAGE_H_
#include "./server/manage_server_handle.h"
#endif

/*\ 配置文件路径 \*/
const char* IniFilePath = "../config.ini";
INIFILE::CSaveIniData gl_SaveIniData;		/*\ 用来存储读取的配置文件信息 \*/

using namespace cinatra;
using namespace UserServer;
using namespace ManageServer;

/*\ 主服务器 \*/
void MainServerFunc(std::string _MainPort)
{
	const int max_thread_num = 4;
	http_server server1(max_thread_num);
	server1.set_http_handler<GET, POST>("/jinzi", [](request& req, response& res) {
		res.set_status_and_content(status_type::ok, "hello world");
	}, enable_cache{ false });
	bool ret = server1.listen("0.0.0.0", _MainPort);
	if (!ret)
	{
		LOG_INFO << "listen failed";
	}
	std::cout << "Main Server Listen Port : " << _MainPort << std::endl;
	server1.run();
}
//用户服务器
void UserServerFunc(std::string _UserPort)
{
	UserServer::CUserServerHandle* oUserServer = new UserServer::CUserServerHandle(_UserPort, gl_SaveIniData);
	/*\ 处理路由信息 \*/
	oUserServer->user_server_router();
	/*\ 运行服务器 \*/
	oUserServer->user_server_run();
}
//后台管理服务器
void ManageServerFunc(std::string _ManagePort)
{
	ManageServer::CBackstageManage* oManageServer = new ManageServer::CBackstageManage(_ManagePort);
	/*\ 处理路由信息 \*/
	oManageServer->manage_server_router();
	/*\ 运行服务器 \*/
	oManageServer->manage_server_run();
}
/*\ 主函数 \*/
int main(int argc, char* argv[]) {
	nanolog::initialize(nanolog::GuaranteedLogger(), "/tmp/", "nanolog", 1);
	std::map<std::string, std::string> mapPort;					//存储端口信息的map集合
	std::map<std::string, std::string>::iterator itMainPort;	//主服务器端口
	std::map<std::string, std::string>::iterator itUserPort;	//用户服务器端口
	std::map<std::string, std::string>::iterator itManagePort;
	gl_SaveIniData.ReadIniFile(IniFilePath);
	mapPort = INIFILE::CSaveIniData::GetInstance()->GetPortInfo();
	itMainPort = mapPort.find("main_port");
	itUserPort = mapPort.find("user_port");
	itManagePort = mapPort.find("manage_port");
	/*\ 用户服务器 \*/
	UserServerFunc(itUserPort->second);
	/*\ 后台管理服务器 \*/
	ManageServerFunc(itManagePort->second);
	/*\ 主服务器 \*/
	MainServerFunc(itMainPort->second);
	return 0;
}