/**************************************************************
 * @file test_boost_bind_timer_class.cpp										  
 * @date 2019/07/12 11:37		
 * @author Jinzi                                              
 * @Contact: 2493349541@qq.com							      
 * @brief 单线程模式下的 计时器				  
***************************************************************/
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace std;

class CPrint
{
public:
	CPrint(boost::asio::io_context& _io, int _seconds) :
		m_timer(_io, boost::asio::chrono::seconds(_seconds)), m_count(0) {
		m_timer.async_wait(boost::bind(&CPrint::print, this));
	}
	~CPrint() { std::cout << "count : " << m_count << std::endl; }
public:
	void print()
	{
		if (m_count < 5)
		{
			std::cout << m_count << std::endl;
			++m_count;
			m_timer.expires_at(m_timer.expiry() + boost::asio::chrono::seconds(1));
			m_timer.async_wait(boost::bind(&CPrint::print, this));
		}
	}
private:
	boost::asio::steady_timer m_timer;
	int m_count;
};

int main(int argc, char* argv[])
{
	boost::asio::io_context io;
	shared_ptr<CPrint> pPrint(new CPrint(io, 1));
	io.run();
	system("pause");
	return 0;
}