#include<stdio.h>
#include "q8_a.c"

int integrate(struct term **p) {
   if (p == NULL) {
      return -1;
   } else if (*p == NULL) {
      return 0;
   } else {
      (*p)->pow = ((*p)->pow)+1;
      (*p)->coeff = ((*p)->coeff)/((*p)->pow);
      return integrate(&((*p)->next));
   }
}
