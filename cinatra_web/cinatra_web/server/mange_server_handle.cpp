#include "manage_server_handle.h"
#include <boost/thread/thread.hpp>
#include <iostream>
#ifndef _SERVER_ROUTER_H_
#include "../router/router.h"
#endif
#ifndef _SAVE_INI_DATA_
#include "../inifile/save_ini_data.h"
#endif
http_server gl_manage_server(4);
 /****************************************!
 *@brief  ���캯��
 *@author Jinzi
 *@date   2019/06/21 17:43:11
 *@param[in]  _port �����˿�
 *@param[out] 
 *@return     
 ****************************************/
ManageServer::CBackstageManage::CBackstageManage(std::string _port)
{
	this->m_sPort = _port;
	bool iRet = gl_manage_server.listen("0.0.0.0", static_cast<std::string>(_port));
	if (!iRet)
	{
		std::cout << "UserServer Listen Port : " << _port << " Failed" << std::endl;
	}
	gl_manage_server.set_base_path("base_path", "/feather");
	gl_manage_server.enable_http_cache(false);//set global cache
	gl_manage_server.set_res_cache_max_age(86400);
	gl_manage_server.set_cache_max_age(5);
}

 /****************************************!
 *@brief  ��������
 *@author Jinzi
 *@date   2019/06/21 17:47:29
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
ManageServer::CBackstageManage::~CBackstageManage()
{
}
/****************************************!
 *@brief  ����������
 *@author Jinzi
 *@date   2019/06/20 14:04:50
 *@param[in]
 *@param[out]
 *@return
 ****************************************/
void ManageServer::CBackstageManage::manage_server_run()
{
	std::cout << "ManageSerer Listen Port : " << this->m_sPort << std::endl;
	boost::thread thread(ThreadRun);
}
/****************************************!
*@brief  �����߳̿�������
*@author Jinzi
*@date   2019/06/20 16:19:17
*@param[in]
*@param[out]
*@return
****************************************/
void ManageServer::ThreadRun()
{
	gl_manage_server.run();
}

/*\ �ж����ĸ�·�� \*/
void ManageServer::CBackstageManage::manage_server_router()
{
	/*\ ��ѯ�û���Ϣ \*/
	gl_manage_server.set_http_handler<GET, POST>(MANAGE_SERVER_USERINFO, [=](cinatra::request& req, cinatra::response& res) {
		this->manage_select_userinfo(req, res);
	});
}