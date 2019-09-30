#pragma once
#ifndef _TIMER_H_JINZI_
#include <iostream>
#include <boost/timer/timer.hpp>
void Timer()
{
	{
		boost::timer::cpu_times cpu_time;
		boost::timer::cpu_timer cpu_timer;
		boost::int_least64_t time = 1;
		cpu_timer.start();
		for (int i = 0; i < 2000; i++)
		{
			for (int j = 0; j < 10000000; j++)
			{
				cpu_time = cpu_timer.elapsed();
				if ((cpu_time.wall) == time)
				{
					cout << "Success" << endl;
				}
			}
		}
		cpu_timer.stop();
		std::cout << cpu_timer.format() << std::endl;
	}
}
#endif