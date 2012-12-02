#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 2

int main(int argc, char *argv[]) 
{
	
	omp_set_num_threads(NUM_THREADS);
	
	int i = 0;
	#pragma omp parallel 
	{
		for (i; i < 10; i++)
		{
			printf("%i \n", i);
		}
	}
	
	return 0;
}