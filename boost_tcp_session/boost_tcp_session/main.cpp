#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/ini_parser.hpp>
using namespace std;
using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session>
{
public:
	//只能使用这中赋值
	Session(tcp::socket _socket) :m_socket(std::move(_socket)) 
	{
		memset(m_data, 0, sizeof(m_data));
	}
public:
	void Start()
	{
		do_read();
	}
	void do_read()
	{
		auto self(shared_from_this());
		m_socket.async_read_some(boost::asio::buffer(m_data, MAX_LENGTH),
			[this, self](boost::system::error_code ec, std::size_t length)
		{
			if (!ec)
			{
				std::cout << "recv data : " << m_data << std::endl;
				do_write(length);
			}
		});
	}
	void do_write(std::size_t length)
	{
		auto self(shared_from_this());
		m_socket.async_write_some(boost::asio::buffer(m_data, length),
			[this, self](boost::system::error_code ec, std::size_t MAX_LENGTH)
		{
			if (!ec)
			{
				do_read();
			}
		});
	}
private:
	tcp::socket m_socket;
	enum
	{
		MAX_LENGTH = 1024
	};
	char m_data[MAX_LENGTH];
};

class Server
{
public:
	Server(boost::asio::io_context& io_context, unsigned short port) :
		m_accept(io_context, tcp::endpoint(tcp::v4(), port))
	{
		do_accept();
	}
public:
	void do_accept()
	{
		m_accept.async_accept([this](boost::system::error_code ec,
			tcp::socket socket) {
			if (!ec)
			{
				std::make_shared<Session>(std::move(socket))->Start();
			}
			do_accept();
		});
	}
private:
	tcp::acceptor m_accept;
};

int main(int argc, char *argv[])
{
	boost::property_tree::ptree oParent, oChild;
	read_ini("./config.ini", oParent);
	oChild = oParent.get_child("PORT");
	unsigned short port = oChild.get<unsigned short>("MainPort");
	boost::asio::io_context io1;
	boost::asio::io_context io2;
	boost::asio::io_context io3;
	Server s1(io1, 10086);
	Server s2(io2, 10087);
	Server s3(io3, 10089);
	io1.run();
	io2.run();
	io3.run();
	system("pause");
	return 0;
}