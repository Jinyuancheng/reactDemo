// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
// 当使用预编译的头时，需要使用此源文件，编译才能成功。

#define EXTERN extern "C" __declspec(dllexport)

typedef struct
{
	int id;
	std::string name;
}STUDENT,*PSTUDENT;

typedef void(*CallBack)(STUDENT);
CallBack gl_callback = nullptr;

void send_data(const boost::system::error_code& e)
{
	STUDENT oStu;
	oStu.id = 1;
	oStu.name = "jinzi";
	if (gl_callback != nullptr)
	{
		gl_callback(oStu);
	}
}

EXTERN void regist_callback_func(CallBack _callback) 
{
	if (_callback != nullptr) 
	{
		gl_callback = _callback;
	}
	boost::asio::io_context io;
	boost::asio::steady_timer time(io, boost::asio::chrono::seconds(5));
	time.async_wait(send_data);
	io.run();
}

