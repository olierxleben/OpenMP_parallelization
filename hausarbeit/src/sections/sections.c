#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N     50
#define NUM_THREADS 2

int main (int argc, char *argv[]) {
	int i, nthreads, tid;
	float a[N], b[N], res_sum[N], res_multi[N];
	
	// Initialize the arrays with some values
	for (i=0; i<N; i++) {
		a[i] = i * 1.5;
		b[i] = i + 42.0;
		res_sum[i] = res_multi[i] = 0.0;
	}
	// running with 2 threads
	#pragma omp parallel shared(a,b,res_sum,res_multi,nthreads) private(i,tid) num_threads(NUM_THREADS)
  	{
		tid = omp_get_thread_num();
		
		if (tid == 0) {
			nthreads = omp_get_num_threads();
			printf("Num threads : %d\n", nthreads);
    	}
		printf("Thread %d  is starting...\n",tid);
		#pragma omp sections
    	{
			#pragma omp section
			{
				printf("Thread %d is doing section 1\n",tid);
				
				for (i=0; i<N; i++) {
					res_sum[i] = a[i] + b[i];
				}
				sleep(tid+2);  // some delay
			} // first section ends here
			
			#pragma omp section
			{
				printf("Thread %d is doing section 2\n",tid);
				
				for (i=0; i<N; i++) {
					res_multi[i] = a[i] * b[i];
				}
				sleep(tid+2); // some delay
			}
		}
		printf("Thread %d finished.\n",tid);
	}

	// results
	printf("result sum:\n");
	for (i=0; i<N; i++) {
		printf("%.2f ", res_sum[i]);
	}
	
	printf("\n\nresult multiplication:\n");
	for (i=0; i<N; i++) {
		printf("%.2f ", res_multi[i]);
	}
		
	printf("\n");
	exit(0);
}