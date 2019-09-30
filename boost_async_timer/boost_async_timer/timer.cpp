/**************************************************************
 * @file timer.cpp										  
 * @date 2019/07/11 17:46		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 同步定时器的应用				  
***************************************************************/
#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;
int main1(int argc,char *argv[])
{
	io_context io;
	steady_timer time(io,boost::asio::chrono::seconds(5));
	time.wait();
	std::cout << "等待了5秒钟，执行阻塞的定时器" << std::endl;
	system("pause");
	return 0;
}