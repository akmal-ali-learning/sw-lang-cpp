#include "timer.h"
#include <stdint.h>
#include <chrono>

uint64_t nanos()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return ns; 
}
double current_time()
{
	return nanos()/(1000000000.0);
}

void Timer::start()
{
	end_time = 0.0;
	start_time = current_time(); 
}


double Timer::finish()
{
	end_time = current_time();
	return end_time - start_time;
}

double Timer::get_elapsed_time()
{
	if(end_time == 0.0)
	{
		return current_time() - start_time;
	}
	else
	{
		return end_time;
	}
}
