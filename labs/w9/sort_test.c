#include <stdio.h>
#include "sort.c"

int bubbleSort(int *array, int size);

int main (void) {
   int arr[10] = {1,5,2,8,3,7,4,9,0,6};
   int* arr2 = NULL;
   int i = 0;
   printf("BEFORE: ");
   for (i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
   }
   printf("\nFUNCTION OUTPUT: %d \nAFTER: ", bubbleSort(arr,10));
   for (i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n\n");

   printf("BEFORE: NULL\n");
   printf("FUNCTION OUTPUT: %d \n", bubbleSort(arr2,10));

  return 0;
}
