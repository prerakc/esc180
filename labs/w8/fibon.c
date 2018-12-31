#include <stdio.h>

int fibo (int n);

int main (void) {
   int i = 0;
   int n = 0;

   scanf("%d",&n);

   for (i = 0; i < n; i++) {
      int f = fibo(i);
      printf("fibo(%d)=%d\n",i,f);
   }
   
   return 0;
}

int fibo (int n) {
   if(n == 0 || n == 1) {
      return 1;
   } else {
      return fibo(n-1)+fibo(n-2);
   }
}
