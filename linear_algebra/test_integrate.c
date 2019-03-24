#include <omp.h>
#include <stdio.h>
#include <math.h>


#include "linear_algebra.h"

static double
f(double x)
{
  return sqrt(1. - x*x);
}

int
main(int argc, char **argv)
{
  double t_beg = Wtime();


  const int N = 1000;
  double dx = 1. / N;

  double sum = 0.;
//    double local_sum=0;
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
      double x0 = i * dx;
      double x1 = (i+1) * dx;
      double val = .5 * (f(x0) + f(x1)) * dx;
#pragma omp critical
      sum += val;
    }
    //sum += local_sum;
    //printf("Thread %d END Time: %lf,  sum = %g\n", omp_get_thread_num(), Wtime(), sum);

  double t_end = Wtime();

  //if(sum < 0.7853) {
  printf("Time: %f,  sum = %g\n", t_end-t_beg, sum);
  //}

  return 0;
}
