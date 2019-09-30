#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using boost::asio::ip::tcp;
class session
	: public std::enable_shared_from_this<session>
{
public:
	session(tcp::socket socket)
		//move会将值移动到指定位置，被移动的变量值将为null
		: socket_(std::move(socket))
	{
	}

	void start()
	{
		do_read();
	}
private:
	void do_read()
	{
		auto self(shared_from_this());
		socket_.async_read_some(boost::asio::buffer(data_, max_length),
			[this, self](boost::system::error_code ec, std::size_t length)
		{
			if (!ec)
			{
				do_write(length);
			}
		});
	}

	void do_write(std::size_t length)
	{
		//返回一个当前类的shared_ptr
		auto self(shared_from_this());
		boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
			[this, self](boost::system::error_code ec, std::size_t /*length*/)
		{
			if (!ec)
			{
				do_read();
			}
		});
	}

	tcp::socket socket_;
	enum { max_length = 1024 };
	char data_[max_length];
};

class Server
{
public:
	Server(boost::asio::io_context& io_context, unsigned short port) :
		accept(io_context, tcp::endpoint(tcp::v4(), port))
	{
		do_accept();
	}
public:
	void do_accept()
	{
		accept.async_accept(
			[this](boost::system::error_code ec, tcp::socket socket)
		{
			if (!ec)
			{
				std::make_shared<session>(std::move(socket))->start();
			}
			do_accept();
		});
	}
private:
	tcp::acceptor accept;
};

int main(int argc, char *argv[])
{
	boost::asio::io_context io_context;
	Server s(io_context, 10086);
	io_context.run();
	system("pause");
	return 0;
}