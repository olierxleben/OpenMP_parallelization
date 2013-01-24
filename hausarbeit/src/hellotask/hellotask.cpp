#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
#define NUM_TASKS 10

int task_index = 0;

int nextTask() {
	int t = -1;
	#pragma omp critical (nextTask)
	{
		if (task_index < NUM_TASKS)
		{
			t = task_index++;
		}
	}
	return t;
}

void runTask(int task) {
	// do sth.
}

int main(int argc, char *argv[])
{	
	#pragma omp parallel num_threads(NUM_THREADS) 
	{
		int task = nextTask();
		while (task != -1) {
			runTask(task);
			task = nextTask();
		}
	}
	return 0;
}
