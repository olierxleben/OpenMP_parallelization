#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	#pragma omp parallel 
	{
		int i;
		for (i = 0; i < 10; i++) { /* some block code */ }
	}
	return 0;
}