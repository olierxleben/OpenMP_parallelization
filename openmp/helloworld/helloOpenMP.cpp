/* 
* 
* Hello World programm prints 'Hello World' message x-times, where x is number of threads in CPU
* @version 1.0
*
* compiled with: 	g++ -fopenmp helloOpenMP.cpp -o test
* running with:		./test
*
* Tested on Mac OS 10.8.2 
*/
#include <stdio.h>
#include <omp.h>

#define NUM_PROCESSORS 2

int main(int argc, char *argv[])
{	
	int tid; // thread id
	
	printf( "Number of Processors/threads in this System: %i\nNumber of Threads use in this Program: %i\n\n", 
		omp_get_num_procs(), NUM_PROCESSORS );
	
	// the next parallel block will be executes with the given value 
	omp_set_num_threads(NUM_PROCESSORS);
	
	// Will print num Threads available on cpu
	// 'omp parallel private' will give you access to private variables like thread_id(tid)
	// each thread has its own private tid 
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("Hello World, created by thread nr %i\n", tid);
	}
	
	printf("\nNow with all \n\n");
	
	omp_set_num_threads(omp_get_num_procs());
	
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("Hello World, created by thread nr %i\n", tid);
	}
}
