#include <stdio.h>
#ifdef _OPENMP
	#include <omp.h>
#endif

#define NUM_THREADS 4

int fib(int n)
{
  int i, j, r;
  if (n<2)
	  return n;
  else {
	  
	  	#pragma omp task shared(i) firstprivate(n)
		{
			i=fib(n-1);
		}
       
		#pragma omp task shared(j) firstprivate(n)
		{
			j=fib(n-2);
		}
	
		#pragma omp taskwait
			r = i + j;
     	
		return r;
	}
}

int main()
{
	int n = 7;
	
  	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel shared(n)
	{
    	#pragma omp single
    	printf ("\n Fibunacci von n = %d => %d\n", n, fib(n));
  	}
}
