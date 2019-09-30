#include <iostream>
#include <boost/asio.hpp>
using namespace std;

void Print(const boost::system::error_code& e)
{
	std::cout << "异步定时器，相隔5秒后执行" << std::endl;
}

int main2(int argc, char* argv[])
{
	//io_context是所有asio操作的基础
	boost::asio::io_context io;
	boost::asio::steady_timer time(io, boost::asio::chrono::seconds(5));
	time.async_wait(&Print);
	std::cout << "异步回调执行后 : " << std::endl;
	io.run();//用来启用调用回调函数 ，不使用的话，不调用回调函数
	system("pause");
	return 0;
}