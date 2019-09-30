#include "./user_server_handle.h"

#ifndef _JINZIUTILS_H_
#include "../utils/utils.h"
#endif

/****************************************!
*@brief  处理用户登录
*@author Jinzi
*@date   2019/06/21 14:45:14
*@param[in]
*@param[out]
*@return
****************************************/
void UserServer::CUserServerHandle::user_login(cinatra::request& req, cinatra::response& res)
{
	auto aClientData = req.body();
	nlohmann::json jResData;
	if (req.body().empty()) 
	{
		jResData["success"] = true;
		jResData["msg"] = "Request Args Null";
		res.render_json(jResData);
	}
	else
	{
		std::cout << "Client Request Login Data : " << req.body().data() << std::endl;
		/*std::vector<std::string> vecData = JinziUtils::GetInstance()->UtilsUrlToSerialize((std::string)aClientData);
		std::string username = JinziUtils::GetInstance()->UtilsStringWithInString(vecData, "username");
		std::string password = JinziUtils::GetInstance()->UtilsStringWithInString(vecData, "password");
		if (!username.empty())
		{
			std::cout << "UserName Is Null" << std::endl;
			return;
		}
		std::string sSql = "select * from user where user_name = " + username;
		this->m_oMySql->mysql_select(sSql);
		MYSQL_RES* SelRes = this->m_oMySql->get_select_result();
		if (SelRes == NULL)
		{
			jResData["success"] = false;
			jResData["msg"] = "UserName Not Exit";
			res.render_json(jResData);
		}
		else
		{*/
			jResData["success"] = true;
			jResData["username"] = "jinzi";
			jResData["password"] = "111111";
			res.render_json(jResData);
		//}
		//vecData.~vector();
	}
}
 /****************************************!
 *@brief  用户微信登录
 *@author Jinzi
 *@date   2019/06/21 15:04:07
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_wx_login(cinatra::request& req, cinatra::response& res)
{
	res.render_string("User WX Login");
}
 /****************************************!
 *@brief  用户qq登录
 *@author Jinzi
 *@date   2019/06/21 15:05:24
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_qq_login(cinatra::request& req, cinatra::response& res)
{
	res.render_string("User QQ Login");
}
 /****************************************!
 *@brief  用户手机登陆
 *@author Jinzi
 *@date   2019/06/21 15:09:43
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_phone_login(cinatra::request& req, cinatra::response& res)
{
	res.render_string("User Phone Login");
}
 /****************************************!
 *@brief  后台管理登录
 *@author Jinzi
 *@date   2019/06/24 14:37:04
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_mange_login(cinatra::request& req, cinatra::response& res)
{
	res.render_string("User Mange Login");
}