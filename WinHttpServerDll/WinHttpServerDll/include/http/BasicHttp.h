/***********************************************************

			封装http服务的基本操作

***********************************************************/
#pragma once
#ifndef _BASICHTTP_H_
#define _BASICHTTP_H_

#include "../mongoose/mongoose.h"
#include "../router/router_regist.h"
#include "../utils/utils.h"
//重命名结构体
typedef struct mg_mgr Manager;				//用来管理事件
typedef struct mg_connection Connection;	//连接
typedef struct http_message ClientSendData; //用来管理客户端传送过来的数据
typedef struct mg_str DataBody;				//存储客户端发送的具体数据

class BasicHttp
{
public:
	BasicHttp();
	~BasicHttp();
public:
	//处理各种数据的头
	static void EventHandle(Connection* _Conn, int _Ev, void* _P);
	//用来处理各种路由的方法
	static void ManagerHandleRouter(Connection* _Conn, ClientSendData* _HttpMessage);
	//给客户端发送数据（响应）SendData需要拼接成JSON类型
	static void ManagerServerToClientData(Connection* _Connect, const char* _SendData);
	//处理Test路由
	static void ManagerHandleTest(Connection* _Connect,ClientSendData* _ReqData);
	//发送客户端请求数据为空
	static void ManagerSendClientReqDataNull(Connection* _Connect);
	//解析客户端发送的数据
	static void ManagerResolver(DataBody* _DataBody,const char* _Name,char* _SaveBuf,size_t _SizeSaveBuf);
public:
	//初始化mg_mgr（Manager）结构体
	void ManagerInit();
	//绑定监听并返回一个连接
	void ManagerBind(const char* _Port);
	//监听http
	void ManagerSetHttp();
	//轮询
	void ManagerPoll();
	//得到连接
	Connection* ManagerGetConn();
private:
	Manager m_Manger;	//定义一个管理事件的实例
	Connection* m_Conn; //连接的实例
};	

#endif


