#ifndef __CONSUME__WATCH__
#define __CONSUME__WATCH__

#include<stdint.h>
#include<sys/time.h>

class stopwatch
{
	public:
			explicit stopwatch(bool auto_start=true);
			
			int64_t getUStime() const;

	private:
			int64_t getLasttime() const; 

    private:
    		bool m_is_runing;
    		int64_t m_start_time;
};

#endif
