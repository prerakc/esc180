#include <stdio.h>

int main (void ) {
   int a[10] = {0,1,2,3,4,5,6,7,8,9};
   int i = 0;
   printf("the size of an integer in my version of C is %d\n", sizeof(int));
   printf("a is %d\n",a);
   for (i = 0; i < 10; i++) {
      printf(" the ADDRESS of a[%d] is %d\n", i, &(a[i]));
   }
   return 0;
}
