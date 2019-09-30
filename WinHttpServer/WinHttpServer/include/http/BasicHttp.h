/***********************************************************

			��װhttp����Ļ�������

***********************************************************/
#pragma once
#ifndef _BASICHTTP_H_
#define _BASICHTTP_H_

#include "../mongoose/mongoose.h"
#include "../router/router_regist.h"
#include "../utils/utils.h"
//�������ṹ��
typedef struct mg_mgr Manager;				//���������¼�
typedef struct mg_connection Connection;	//����
typedef struct http_message ClientSendData; //��������ͻ��˴��͹���������
typedef struct mg_str DataBody;				//�洢�ͻ��˷��͵ľ�������

class BasicHttp
{
public:
	BasicHttp();
	~BasicHttp();
public:
	//����������ݵ�ͷ
	static void EventHandle(Connection* _Conn, int _Ev, void* _P);
	//�����������·�ɵķ���
	static void ManagerHandleRouter(Connection* _Conn, ClientSendData* _HttpMessage);
	//���ͻ��˷������ݣ���Ӧ��SendData��Ҫƴ�ӳ�JSON����
	static void ManagerServerToClientData(Connection* _Connect, const char* _SendData);
	//����Test·��
	static void ManagerHandleTest(Connection* _Connect,ClientSendData* _ReqData);
	//���Ϳͻ�����������Ϊ��
	static void ManagerSendClientReqDataNull(Connection* _Connect);
	//�����ͻ��˷��͵�����
	static void ManagerResolver(DataBody* _DataBody,const char* _Name,char* _SaveBuf,size_t _SizeSaveBuf);
public:
	//��ʼ��mg_mgr��Manager���ṹ��
	void ManagerInit();
	//�󶨼���������һ������
	void ManagerBind(const char* _Port);
	//����http
	void ManagerSetHttp();
	//��ѯ
	void ManagerPoll();
	//�õ�����
	Connection* ManagerGetConn();
private:
	Manager m_Manger;	//����һ�������¼���ʵ��
	Connection* m_Conn; //���ӵ�ʵ��
};	

#endif


