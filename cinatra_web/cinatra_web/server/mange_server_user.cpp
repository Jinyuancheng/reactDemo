#include "./manage_server_handle.h"

 /****************************************!
 *@brief  ��ѯ�û���Ϣ
 *@author Jinzi
 *@date   2019/06/21 17:55:44
 *@param[in]  
 *@param[out] 
 *@return     
 ****************************************/
void ManageServer::CBackstageManage::manage_select_userinfo(cinatra::request& req, cinatra::response& res)
{
	res.render_string("Manage Server Select User Info");
}