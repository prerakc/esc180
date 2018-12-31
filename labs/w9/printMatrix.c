#include <stdio.h>

int printMatrix(float *arr, int rows, int cols);

int printMatrix(float *arr, int rows, int cols) {
   int x, y;
   for(x=0;x<rows;x=x+1) {
      for(y=0;y<cols;y=y+1) {
         printf("%8.3f", arr[x*cols + y]);
      }
      printf("\n");
   }
   return 0;
}

int main (void) {
   float arr[2][3];
   int x=0, y=0;
   int i=0;
   int r=0;

   for(x=0;x<2;x++) {
      for(y=0;y<3;y++) {
         arr[x][y]=i;
         i++;
      }
   }

   r=printMatrix((float *)arr,2,3);
   
   return 0;
}
