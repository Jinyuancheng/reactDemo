#include <iostream>
#include <boost/asio.hpp>
using namespace std;

void Print(const boost::system::error_code& e)
{
	std::cout << "�첽��ʱ�������5���ִ��" << std::endl;
}

int main2(int argc, char* argv[])
{
	//io_context������asio�����Ļ���
	boost::asio::io_context io;
	boost::asio::steady_timer time(io, boost::asio::chrono::seconds(5));
	time.async_wait(&Print);
	std::cout << "�첽�ص�ִ�к� : " << std::endl;
	io.run();//�������õ��ûص����� ����ʹ�õĻ��������ûص�����
	system("pause");
	return 0;
}