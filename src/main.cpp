#include <stdio.h>
#include "timer.h"
#include "genetic_algorithm/Simulator/simulator.h"
#include <stdint.h>



int main()
{
	Timer program_timer;
	program_timer.start();

	Simulator sim(1000);
	int waves_survived = sim.run(100);
	printf("Survived %d waves \n", waves_survived);



 	double time_taken = program_timer.finish();
	printf("Program took %.3f seconds \n", time_taken);
	return 0;
}
