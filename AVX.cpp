#include <immintrin.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    time_t endwait;
    time_t start = time(NULL);
    time_t seconds = 10;
    endwait = start + seconds;
    int a = 0;
    printf("start time is : %s", ctime(&start));
    while (start < endwait)
    {
    a++;
  __m256d veca = _mm256_setr_pd(((float)rand()/(float)(RAND_MAX)) * 100000.0, ((float)rand()/(float)(RAND_MAX)) * 100000, ((float)rand()/(float)(RAND_MAX)) * 1000.0, ((float)rand()/(float)(RAND_MAX)) * 100000);

  __m256d vecb = _mm256_setr_pd(((float)rand()/(float)(RAND_MAX)) * 100000.0, ((float)rand()/(float)(RAND_MAX)) * 100000, ((float)rand()/(float)(RAND_MAX)) * 1000.0, ((float)rand()/(float)(RAND_MAX)) * 100000);
  
  __m256d vecc = _mm256_setr_pd(((float)rand()/(float)(RAND_MAX)) * 100000.0, ((float)rand()/(float)(RAND_MAX)) * 100000, ((float)rand()/(float)(RAND_MAX)) * 1000.0, ((float)rand()/(float)(RAND_MAX)) * 100000);
  
  /* Alternately subtract and add the third vector
     from the product of the first and second vectors */
  __m256d result = _mm256_fmaddsub_pd(veca, vecb, vecc);
  
  /* Display the elements of the result vector */
  double* res = (double*)&result;
  printf("%lf %lf %lf %lf\n", res[0], res[1], res[2], res[3]);
  start = time(NULL);
  printf("loop time is : %s\n", ctime(&start));
  printf("loops: %i\n", a);
    };
  return 0;
}