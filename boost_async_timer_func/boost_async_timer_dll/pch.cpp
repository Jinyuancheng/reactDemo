// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include <iostream>
#include <boost/asio.hpp>
// 当使用预编译的头时，需要使用此源文件，编译才能成功。
#define EXTERN extern "C" __declspec(dllexport)

typedef void(*CallBack)(void*);
CallBack gl_callback = nullptr;

void send_data(boost::system::error_code e)
{
	std::cout << "成功" << std::endl;
}
EXTERN void RegistCallBack(CallBack _callback)
{
	if (_callback != nullptr) 
	{
		gl_callback = _callback;
	}
	boost::asio::io_context io;
	boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(2));
	for (int i = 0; i < 4; i++) 
	{
		timer.async_wait(send_data);
		io.run();
	}
}

