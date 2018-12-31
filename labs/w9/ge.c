#include <stdio.h>
#include <stdlib.h>

int ge_fw(float *matrix, int rows, int cols, float *matrix_out) {
   float* gauss = NULL;
   int n = 0;
   int loop = 0;
   int a =0;
   int b = 0;
   
   if (rows*cols == 0) {
      return -1;
   }

   gauss = (float *)malloc(rows*cols*sizeof(float));
   for(a = 0; a < rows; a++) {
      for(b = 0; b < cols; b++) {
         gauss[a*cols+b] = matrix[a*cols+b];
      }
   }

   if (rows >= cols) {
      n = cols;
   } else {
      n = rows;
   }
   
   for(loop = 0; loop < n; loop++) {
      int entPos = 0;
      int k = 0;
      /* If first element of column is zero */
      if (gauss[loop*cols+loop] == 0) {
         /* Find maximal entry in column */
         int maxEnt = gauss[loop*cols+loop];
         int search = 0;
         if (maxEnt < 0) {
            maxEnt *= -1;
         }
         entPos = loop*cols+loop;
         for(search = loop+1; search < rows; search++) {
            int temp = gauss[search*cols+loop];
            if (temp < 0) {
               temp *= -1;
            }
            if (temp > maxEnt) {
               maxEnt = temp;
               entPos = search*cols+loop;
            }
         }
         /* Swap maximum row and current row */
         for (search = 0; search < cols; search++) {
            int orgRow = gauss[loop*cols+search];
            int maxRow = gauss[(entPos-loop)+search];
            gauss[loop*cols+search] = maxRow;
            gauss[(entPos-loop)+search] = orgRow;
         }
      }
      /* Make all rows below this one 0 in current column */
      for(k=loop+1;k<rows;k++) {
         if (gauss[k*cols+loop] != 0) {
            float factor = gauss[k*cols+loop]/gauss[loop*cols+loop];
            int x = 0;
            for (x = loop; x < cols; x++) {
               gauss[k*cols+x] -= factor*gauss[loop*cols+x];
            }
         }
      }
   }

   for(a = 0; a < rows; a++) {
      for(b = 0; b < cols; b++) {
         matrix_out[a*cols+b] = gauss[a*cols+b];
      }
   }

   return 0;
}

int ge_bw(float *matrix, int rows, int cols, float *matrix_out) {
   float* gauss = NULL;
   int n = 0;
   int loop = 0;
   int a =0;
   int b = 0;
 
   if (rows*cols == 0) {
      return -1;
   }
  
   gauss = (float *)malloc(rows*cols*sizeof(float));
   for(a = 0; a < rows; a++) {
      for(b = 0; b < cols; b++) {
         gauss[a*cols+b] = matrix[a*cols+b];
      }
   }
   
   if (rows >= cols) {
      n = cols;
   } else {
      n = rows;
   }

   for(loop = n-1; loop > -1; loop--) {
      /* Find last nonzero row */
      float firstEnt = 0;
      int entRow = 0;
      int entCol = 0;
      int entFound = 0;
      int j = loop;
      int x = 0, y = 0, m = 0;
      int div = 0;
      while ((j >= 0) && (j <= loop) && (entFound == 0)) {
         int k = 0;
         for (k = 0; k < cols; k++) {
            if (gauss[j*cols+k] != 0) {
               firstEnt = gauss[j*cols+k];
               entRow = j;
               entCol = k;
               entFound = 1;
               break;
            }
         }
         j=j-1;
      }

      /* Normalize row */
      div = gauss[entRow*cols+entCol];
      for (m = 0; m < cols; m++) {
         gauss[entRow*cols+m] /= div;
      }

      /* Make other values in current column 0 */
      for (x = entRow-1; x > -1; x--) {
         int factor = gauss[x*cols+entCol]/gauss[entRow*cols+entCol];
         for (y = 0; y < cols; y++) {
            gauss[x*cols+y] -= factor*gauss[entRow*cols+y];
         }
      }
   }

   for(a = 0; a < rows; a++) {
      for(b = 0; b < cols; b++) {
         matrix_out[a*cols+b] = gauss[a*cols+b];
      }
   }
   
   return 0;
}
