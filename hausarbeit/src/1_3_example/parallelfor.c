#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	
	int tid;
	#pragma omp parallel private(tid)
	{
		int i;
		#pragma omp for
			for (i = 0; i < 10; i++) { tid = omp_get_thread_num(); printf("%i, from %i\n", i, tid);}
	}
	return 0;
}