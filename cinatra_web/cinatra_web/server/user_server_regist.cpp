#include "./user_server_handle.h"

 /****************************************!
 *@brief  �û�ע��
 *@author Jinzi
 *@date   2019/06/21 15:00:52
 *@param[in]  req�������ݶ��� res��Ӧ���ݶ���
 *@param[out] 
 *@return     
 ****************************************/
void UserServer::CUserServerHandle::user_regist(cinatra::request& req, cinatra::response& res)
{
	res.render_string("User Server Regist");
}