#include <stdio.h>

int anlboard (int *T, int sizeT);

int main (void) {
   int arr[9] = {1,1,1,0,0,0,0,0,0};
   printf("%d\n",anlboard(arr,9));
}

int anlboard(int *T, int sizeT) {
   int n_opens = 0;
   int i = 0;

   int numX = 0;
   int numO = 0;

   int xWon = 0;
   int yWon = 0;
    
   if(sizeT != 9) {
       return -1;
    }
    
   for (i = 0; i < sizeT; i++) {
      if (T[i] >= 0 && T[i] <= 2) {
         return -1;
      } else {
	 if(T[i] == 1) {
            numX += 1;
         } else if (T[i] == 2) {
            numO += 1;
         }
      }
   }
    
   if((numX-numO > 1) || (numO-numX > 1)) {
        return -1;
   }
    
   if ((T[0] == T[1]) && (T[1] == T[2]) && (T[2] != 0)) {
      if (T[0] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[3] == T[4]) && (T[4] == T[5]) && (T[5] != 0)) {
      if (T[3] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[6] == T[7]) && (T[7] == T[8]) && (T[8] != 0)) {
      if (T[6] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[0] == T[3]) && (T[3] == T[6]) && (T[6] != 0)) {
      if (T[0] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[1] == T[4]) && (T[4] == T[7]) && (T[7] != 0)) {
      if (T[1] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[2] == T[5]) && (T[5] == T[8]) && (T[8] != 0)) {
      if (T[2] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[0] == T[4]) && (T[4] == T[8]) && (T[8] != 0)) {
      if (T[0] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[2] == T[4]) && (T[4] == T[6]) && (T[6] != 0)) {
      if (T[2] == 1) {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }

   if((xWon == 1) && (yWon == 0)) {
      return 1;
   } else if ((xWon == 0) && (yWon == 1)) {
      return 2;
   } else if ((xWon == 1) && (yWon == 1)) {
      return -1;
   }

   for (i = 0; i < sizeT; i++) {
      if (T[i] == 0) {
         n_opens += 1;
       }
   }

   if (n_opens == 0) {
      return 3;
   }

   else {
      return 0;
   }
}
