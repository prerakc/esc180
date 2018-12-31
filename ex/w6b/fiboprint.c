#include <stdio.h>
#include "fibonum_rec.h"

int genfibo (int n);

int main(void)
{
   int i = 0;
   int n = 0;

   printf("Enter nth fib num: ");
   scanf("%d",&n);

   int arr[n];

   for (i = 0; i < n; i++)
   {
      int num = genfibo(i);
      arr[i] = num;
   }

   for (i = 0; i < n; i++)
   {
      printf("Fib num %d is %d\n",i,arr[i]);
   }

   return 0;
}
