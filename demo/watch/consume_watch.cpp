#include "consume_watch.h"

int64_t getNowUstime()
{
	timeval tv;
	gettimeofday(&tv,0);
	return (int64_t)tv.tv_sec*1000000+(int64_t)tv.tv_usec;
}

stopwatch::stopwatch(bool auto_start):m_is_runing(auto_start),m_start_time(0)
{
	if(auto_start)
		m_start_time=getNowUstime();
}

int64_t stopwatch::getUStime() const
{
	if(m_is_runing)
		return getLasttime();
	else
		return 0;
}

int64_t stopwatch::getLasttime() const
{
	return getNowUstime()-m_start_time;
}
