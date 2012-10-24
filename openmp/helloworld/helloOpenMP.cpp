/* 
	* 
	* Hello World programm prints 'Hello World' message x-times, where x is number of threads in CPU
	* @version 1.0
	*
	* compiled with: 	g++ -fopenmp helloOpenMP.cpp -o test
	* running with:		./test
	*
	* Tested on Mac OS 10.8.2 
	* Tested on Linux 3.2.0-29 
 */

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	// Will print num Threads available on cpu
	#pragma omp parallel
	{
		printf("Hello World\n");
	}
}
