#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "./jinzi_log.h"
using namespace std;

int main1(int argc,char *argv[])
{
	using namespace boost::gregorian;
	date today = day_clock::local_day();
	std::string time;
	time = std::to_string(today.week_number()) + ".log";
	std::cout << time << std::endl;
	jinzi::CLog* log = new jinzi::CLog(time);
	log->BaseWriteLog(time, severity_level::warning, "我类个去");
	system("pause");
	return 0;
}