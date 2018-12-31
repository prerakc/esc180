#include <stdio.h>

int bubbleSort(int *array, int size) {
   if ((array == NULL) || (size == 0)) {
      return -1;
   } else {
      int swapped = 1, j = 1;
      while (swapped) {
         swapped = 0;
         for (j=1;j<size;j++) {
            if (array[j-1] > array[j]) {
               int temp = array[j];
               array[j] = array[j-1];
               array[j-1] = temp;
               swapped = 1;
            }
         }
      }
      return 0;
   }
}
