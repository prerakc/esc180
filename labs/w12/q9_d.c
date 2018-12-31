#include<stdio.h>
#include<stdlib.h>

int fil(float *matrixIn, int rows, int cols, float **matrixOut) {
   int i = 0;
   if (matrixIn == NULL) {
      return -1;
   }
   (*matrixOut) = (float *)malloc(sizeof(float)*rows*cols);
   for (i = 0; i < rows*cols; i = i + 1) {
      if (matrixIn[i] < 0) {
         (*matrixOut)[i] = 0;
      } else {
         (*matrixOut)[i] = matrixIn[i];
      }
   }
   return 0;
}
