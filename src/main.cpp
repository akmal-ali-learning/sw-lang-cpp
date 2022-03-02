#include <stdio.h>
#include "timer.h"


uint32_t
compute_task()
{
	uint32_t data = 1;
	for(int i = 0; i < 1000000000; ++i)
	{
		data = data ^ i;
	}
	return data;
}






int main()
{
	Timer program_timer;
	program_timer.start();
	uint32_t check_value = compute_task();
       	double time_taken = program_timer.finish();
	if(check_value)
		printf("Program took %.3f seconds \n", time_taken);
	return 0;
}
