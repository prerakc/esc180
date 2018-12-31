#include<stdio.h>

int main (void) {
   int *b;
   int **a;
   int c = 10;
   int d = 20;
   int q = 30;
   b = &c;
   a = &b;
   q=**a;
   *b=0;
   d = c + 100;
   q = q + 100;
   printf("double pointer a points to %d\n",**a);
   printf("pointer b points to %d\n",*b);
   printf("c equals %d\n",c);
   printf("d equals %d\n",d);
   printf("q equals %d\n",q); 
   return 0;
}
