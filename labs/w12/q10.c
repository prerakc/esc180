#include<stdio.h>
#include<stdlib.h>

int nsum(float *a, float *b, int n, float **output) {
   int i = 0;
   if ((a == NULL) || (b == NULL)) {
      return -1;
   }
   (*output) = (float *)malloc(sizeof(float)*n);
   for (i = 0; i < n; i = i + 1) {
      (*output)[i] = a[i] + b[i];
   }
   return 0;
}
