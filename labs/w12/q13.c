#include<stdio.h>

typedef struct mdata {
   int valid;
   int value;
   int frequency;
} mdata;

int getmode(mdata *m, int *mode, int size) {
   int i = 0, val = 0, freq = 0;
   if (m == NULL || mode == NULL) {
      return -1;
   }
   for (i = 0; i < size; i = i +1) {
      if (m[i].valid == 1) {
         if (m[i].frequency > freq) {
            freq = m[i].frequency;
            val = m[i].value;
         }
      }
   }
   (*mode) = val;
   return 0;
}
