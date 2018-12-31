#include <stdio.h>
#include "ge.c"

int ge_fw(float *matrix, int rows, int cols, float *matrix_out);
int ge_bw(float *matrix, int rows, int cols, float *matrix_out);
int printMatrix(float *arr, int rows, int cols);

int printMatrix(float *arr, int rows, int cols) {
   int x = 0, y = 0;
   for (x=0;x<rows;x++) {
      for (y=0;y<cols;y++) {
         printf("%8.3f", arr[x*cols+y]);
      }
      printf("\n");
   }
   printf("-----------\n");
   
   return 0;
}

int main (void) {
   float test1[3][3] = {1,2,3,4,5,6,7,8,9};
   float test2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
   float test3[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
   float *test4 = NULL;

   float fw1[3][3];
   float fw2[3][4];
   float fw3[4][3];
   float *fw4 = NULL;

   float bw1[3][3];
   float bw2[3][4];
   float bw3[4][3];
   float *bw4 = NULL;

   int fw1_return = 1;
   int fw2_return = 1;
   int fw3_return = 1;
   int fw4_return = 1;

   int bw1_return = 1;
   int bw2_return = 1;
   int bw3_return = 1;
   int bw4_return = 1;

   fw1_return = ge_fw((float *)test1, 3, 3, (float *)fw1);
   fw2_return = ge_fw((float *)test2, 3, 4, (float *)fw2);
   fw3_return = ge_fw((float *)test3, 4, 3, (float *)fw3);
   fw4_return = ge_fw((float *)test4, 0, 0, (float *)fw4);

   bw1_return = ge_bw((float *)fw1, 3, 3, (float *)bw1);
   bw2_return = ge_bw((float *)fw2, 3, 4, (float *)bw2);
   bw3_return = ge_bw((float *)fw3, 4, 3, (float *)bw3);
   bw4_return = ge_bw((float *)fw4, 0, 0, (float *)bw4);

   printf("ORIGINAL\n");
   printMatrix((float *)test1, 3, 3);
   printf("AFTER FW\n");
   printMatrix((float *)fw1, 3, 3);
   printf("AFTER BW\n");
   printMatrix((float *)bw1, 3, 3);
   printf("OUTPUT: %d\n", bw1_return);

   printf("ORIGINAL\n");
   printMatrix((float *)test2, 3, 4);
   printf("AFTER FW\n");
   printMatrix((float *)fw2, 3, 4);
   printf("AFTER BW\n");
   printMatrix((float *)bw2, 3, 4);
   printf("OUTPUT: %d\n", bw2_return);

   printf("ORIGINAL\n");
   printMatrix((float *)test3, 4, 3);
   printf("AFTER FW\n");
   printMatrix((float *)fw3, 4, 3);
   printf("AFTER BW\n");
   printMatrix((float *)bw3, 4, 3);
   printf("OUTPUT: %d\n", bw3_return);

   printf("ORIGINAL\n");
   printMatrix((float *)test4, 0, 0);
   printf("AFTER FW\n");
   printMatrix((float *)fw4, 0, 0);
   printf("AFTER BW\n");
   printMatrix((float *)bw4, 0, 0);
   printf("OUTPUT: %d\n", bw4_return);

   return 0;     
}
