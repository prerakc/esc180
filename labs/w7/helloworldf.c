#include <stdio.h>

float absval (float n);
float bsqrt(float n, float a);

int main(void) {
   int i;
   for(i=0;i<10;i++) {
      float sqrt = bsqrt((float)i,0.001);
      printf("The sqrt of %d is %f\n",i,sqrt);
   }

   return 0;
}

float absval(float n) {
   if (n >= 0) {
      return n;
   }
   else {
      return -n;
   }
}

float bsqrt(float x, float a) {
   float est = x/2;
   int run = 1;

   while (run == 1) {
      if (absval(x-est*est) > a) {
         est = (est+x/est)/2;
      }
      else {
         run = 0;
      }
   }

   return est;
}
