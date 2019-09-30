#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace std;
void print(const boost::system::error_code& /*e*/,
	boost::asio::steady_timer* t, int* count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		//++(*count);
		//设置定时器的过期时间为绝对时间（expires_at）
		t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
		t->async_wait(boost::bind(print,
			boost::asio::placeholders::error, t, count));
	}
}
int main1()
{
	boost::asio::io_context io;
	int count = 0;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
	t.async_wait(boost::bind(print,
		boost::asio::placeholders::error, &t, &count));
	io.run();
	std::cout << "Final count is " << count << std::endl;
	system("pause");
	return 0;
}