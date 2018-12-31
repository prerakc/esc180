#include <stdio.h>

float bsqrt(float x, float tol);
float absval(float n);

float absval(float n) {
   if (n >= 0) {
      return n;
   }
   else {
      return -n;
   }
}

float bsqrt(float x, float tol) {
   float est = x/2;

   while (absval(x-est*est) > tol) {
      est = (est+x/est)/2;
   }

   return est;
}
