#include "../../include/http/BasicHttp.h"

BasicHttp::BasicHttp()
{
}


BasicHttp::~BasicHttp()
{
}

void BasicHttp::ManagerInit()
{
	mg_mgr_init(&this->m_Manger, NULL);
}

void BasicHttp::ManagerBind(const char* _Port)
{
	this->m_Conn = mg_bind(&this->m_Manger, _Port, EventHandle);
	printf("HttpServer Listen Port : %s\n",_Port);
}
//监听http
void BasicHttp::ManagerSetHttp()
{
	mg_set_protocol_http_websocket(this->m_Conn);
}

//轮询
void BasicHttp::ManagerPoll()
{
	for (;;) {
		mg_mgr_poll(&this->m_Manger, 1000);
	}
	mg_mgr_free(&this->m_Manger);
}

void BasicHttp::EventHandle(Connection* _Conn, int _Ev, void* _UserData)
{
	//客户端发送过来的数据
	ClientSendData *iHttpMessage = (ClientSendData*)_UserData;
	switch (_Ev)
	{
	case MG_EV_HTTP_REQUEST:
		BasicHttp::ManagerHandleRouter(_Conn, iHttpMessage);
		break;
	}
}
//得到连接
Connection* BasicHttp::ManagerGetConn()
{
	return this->m_Conn;
}

//给客户端发送数据
void BasicHttp::ManagerServerToClientData(Connection* _Connect, const char* _SendData)
{
	/* Send headers */
	mg_printf(_Connect, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
	//要发送的数据
	mg_printf_http_chunk(_Connect, _SendData);
	//表示响应结束
	mg_send_http_chunk(_Connect, "", 0); /* Send empty chunk, the end of response */
}

//发送客户端请求数据为空
void BasicHttp::ManagerSendClientReqDataNull(Connection* _Connect)
{
	/* Send headers */
	mg_printf(_Connect, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
	//要发送的数据
	const char* iNullStr = "{ \"result\":\"Client Request Data Null!!!\" }";
	mg_printf_http_chunk(_Connect, iNullStr);
	//表示响应结束
	mg_send_http_chunk(_Connect, "", 0); /* Send empty chunk, the end of response */
}

//解析客户端发送的数据
//_DataBody mg_str结构体 存储客户端发送的具体数据
//_Name 客户端发送过来的 变量的名称
//_SaveBuf 要将解析后的该变量的值存放的缓冲区数据
//_SizeSaveBuf 缓冲区数据的大小 sizeof(_SaveBuf)
void BasicHttp::ManagerResolver(DataBody* _DataBody, const char* _Name, char* _SaveBuf, size_t _SizeSaveBuf)
{
	mg_get_http_var(_DataBody, _Name, _SaveBuf, _SizeSaveBuf);
}

//处理Test路由
//_Connect 客户端的连接句柄
//_ReqData 客户端请求的数据
void BasicHttp::ManagerHandleTest(Connection* _Connect, ClientSendData* _ReqData)
{
	if (&_ReqData->body.len == (size_t)0)
	{
		//给客户端发送请求数据为null
		BasicHttp::ManagerSendClientReqDataNull(_Connect);
	}
	else
	{
		//用来接收客户端发送过来的数据
		char buf[100];
		memset(buf, 0, sizeof(buf));
		memcpy(buf, _ReqData->body.p, sizeof(buf) < _ReqData->body.len ? sizeof(buf) - 1 : _ReqData->body.len);
		printf("Client Send Data : %s\n",buf);
		//用来接收解析之后的数据
		char name[100];
		char pass[100];
		//mg_get_http_var用来接收数据
		BasicHttp::ManagerResolver(&_ReqData->body, "name", name, sizeof(name));
		BasicHttp::ManagerResolver(&_ReqData->body, "pass", pass, sizeof(pass));
		printf("n1 = %s\n",name);
		printf("n2 = %s\n", pass);
		const char* iResData = "{ \"result\":\"success\" }";
		BasicHttp::ManagerServerToClientData(_Connect, iResData);
	}
}

//用来处理各种路由的消息
//_clientSendMessage 客户端发送过来的数据
//hm 就是http_message 结构体 里面存储了客户端发送的具体信息
void BasicHttp::ManagerHandleRouter(Connection* _Conn,ClientSendData* hm)
{
	//用来测试的路由
	//mg_vcmp函数用来判断路由
	if (mg_vcmp(&hm->uri, TEST) == 0) {
		BasicHttp::ManagerHandleTest(_Conn,hm);
	}
	
}

