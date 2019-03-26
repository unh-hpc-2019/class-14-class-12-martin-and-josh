
#include <omp.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// main


int
main(int argc, char **argv)
{
  // single-threaded
  printf("Hi, just starting.\n");

  int sum = 0;
  int num_threads;

  // start running multiple threads
#pragma omp parallel reduction(+:sum)
  {
    int thread_id = omp_get_thread_num();
    num_threads = omp_get_num_threads();
    printf("My number is %d\n", thread_id);
    sum = thread_id;
  }
  // back to single-threaded
  printf("The sum across all threads is %d, expected: %d\n",
	 sum, num_threads * (num_threads - 1) / 2);

  return 0;
}
