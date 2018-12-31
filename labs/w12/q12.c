#include<stdio.h>

typedef struct mdata {
   int valid;
   int value;
   int frequency;
} mdata;

int histogram(int *n, mdata *m, int s) {
   int i = 0, j = 0, found = 0;
   if ((n == NULL) || (m == NULL)) { return -1;}
   for (i = 0; i < s; i = i + 1) {
      found = 0;
      for (j = 0; j < s; j = j + 1) {
         if (m[j].valid == 1) {
            if (m[j].value == n[i]) {
               m[j].frequency = m[j].frequency + 1;
               found = 1;
            }
         } else {
            break;
         }
      }
      if (found == 0) {
         m[i].valid = 1;
         m[i].value = n[i];
         m[i].frequency = 1;
      }
   }
   return 0;
}  
