#ifndef _LOGIN_H_
#include "./login.h"
#endif

#ifndef _JINZIUTILS_H_
#include "../utils/utils.h"
#endif

//************************************     
// ��������: Login   
// ����˵��: Login��Ĺ��캯�� ������ʼ������    
// �� �� ��: ����     
// ��������: 2019/04/17 22:20:05  
// �� �� ֵ:      
// ��    ��:   
//************************************  
nsLogin::Login::Login()
{
	this->m_CHttpServer = NULL;
}
//************************************     
// ��������: LoadLoginRouter   
// ����˵��: ����·�ɵ�    
// �� �� ��: ����     
// ��������: 2019/04/17 21:55:01  
// �� �� ֵ:      
// ��    ��:   
//************************************  
int nsLogin::Login::LoadLoginRouter()
{
	/*\ ���������û���¼��·�� */
	this->m_CHttpServer->set_http_handler<GET, POST, OPTIONS>("/login", [](request& req, response& res) {
		nsLogin::Login::UserLogin(req, res);
	}, enable_cache{ false });
	/*\ ���������û�ע���·�� */
	this->m_CHttpServer->set_http_handler<GET, POST>("/regist", [](request& req, response& res) {
		nsLogin::Login::UserRegist(req, res);
	}, enable_cache{ false });
	return 0;
}
//************************************     
// ��������: SetHttpServer   
// ����˵��: ��������������ָ�������뵽���ļ���    
// �� �� ��: ����     
// ��������: 2019/04/17 21:53:08     
// �� �� ֵ:      
// ��    ��:   _HttpServer �����������ָ��
//************************************  
void nsLogin::Login::SetHttpServer(cinatra::http_server* _HttpServer)
{
	this->m_CHttpServer = _HttpServer;
	Login::LoadLoginRouter();
}
//************************************     
// ��������: UserLogin   
// ����˵��: �û���¼�ķ���    
// �� �� ��: ����     
// ��������: 2019/04/17 22:23:53  
// �� �� ֵ:      
// ��    ��:   req �������ݶ��� res ��Ӧ���ݶ���
//************************************  
void nsLogin::Login::UserLogin(request& req, response& res)
{
	auto Data = req.body();
	if (Data.empty())
	{
		res.render_string("�������Ϊ��");
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
			json["msg"] = "�û���¼�ɹ�";
			res.render_json(json);
		}
		else
		{
			json["result"] = "-1";
			json["msg"] = "�û���¼ʧ��";
			res.render_json(json);
		}
	}
	
}
//************************************     
// ��������: UserRegist   
// ����˵��: �û�ע��    
// �� �� ��: ����     
// ��������: 2019/04/17 22:36:06  
// �� �� ֵ:      
// ��    ��:   req �������ݶ��� res ��Ӧ���ݶ���
//************************************  
void nsLogin::Login::UserRegist(request& req, response& res)
{
	res.render_string("Regist Success");
}