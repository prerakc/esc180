#include<stdio.h>

int isPrime(int n) {
   int i = 0;
   for (i = 2; i < n; i++) {
      if (n % i == 0) {
         return -1;
      }
   }
   return 0;
}

int isPrimeProduct(int n) {
   int i = 0;
   int j = 0;
   for (i = 2; i < n; i++) {
      for (j = 2; j < n; j++) {
         if (i*j == n) {
            if ((isPrime(i) == 0) && (isPrime(j) == 0)) {
               return 0;
            }
         }
      }
   }
   return -1;
}
