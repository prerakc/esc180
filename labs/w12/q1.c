#include<stdio.h>

float average(float *arr, int size);

float average(float *arr, int size) {
   int i = 0;
   float accum = 0;
   for (i = 0; i < size; i = i + 1) {
      accum = accum + arr[i];
   }
   accum = accum/size;
   return accum;
}
