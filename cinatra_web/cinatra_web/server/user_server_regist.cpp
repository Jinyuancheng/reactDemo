#include "./user_server_handle.h"

 /****************************************!
 *@brief  用户注册
 *@author Jinzi
 *@date   2019/06/21 15:00:52
 *@param[in]  req请求数据对象 res响应数据对象
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_regist(cinatra::request& req, cinatra::response& res)
{
	res.render_string("User Server Regist");
}