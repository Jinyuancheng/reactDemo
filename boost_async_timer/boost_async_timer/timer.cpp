/**************************************************************
 * @file timer.cpp										  
 * @date 2019/07/11 17:46		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief ͬ����ʱ����Ӧ��				  
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
	std::cout << "�ȴ���5���ӣ�ִ�������Ķ�ʱ��" << std::endl;
	system("pause");
	return 0;
}