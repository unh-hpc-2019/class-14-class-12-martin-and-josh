
#include <omp.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  //single-threaded
  printf("Hi, just starting.\n");
  //start running multiple threads

  int test = -1;
//#pragma omp parallel
#pragma omp parallel private(test)
  {
    //test=500;
    int thread_id = omp_get_thread_num();
    int n_threads = omp_get_num_threads();
    //printf("Hi, I'm thread %d of %d\n", thread_id, n_threads);
    printf("Hello %d/%d test=%d\n", thread_id, n_threads, test);
    test = thread_id;
  }
  printf("test = %d\n", test);


  printf("almost done\n");
  return 0;
}
