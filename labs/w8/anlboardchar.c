#include <stdio.h>

int anlboard (char *T, int sizeT);

int main (void) {
   char arr[9] = {'X','X','X','-','-','-','-','-','-'};
   printf("%d\n",anlboard(arr,9));
}

int anlboard(char *T, int sizeT) {
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
	 if(T[i] == 'X') {
            numX += 1;
         } else if (T[i] == 'O') {
            numO += 1;
         }
      }
   }

   if((numX-numO > 1) || (numO-numX > 1)) {
        return -1;
   }

   if ((T[0] == T[1]) && (T[1] == T[2]) && (T[2] != '-')) {
      if (T[0] == 'X') {
        xWon = 1;
      } else {
        yWon = 1;
      }
   }
   if ((T[3] == T[4]) && (T[4] == T[5]) && (T[5] != '-')) {
       if (T[3] == 'X') {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[6] == T[7]) && (T[7] == T[8]) && (T[8] != '-')) {
       if (T[6] == 'X') {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[0] == T[3]) && (T[3] == T[6]) && (T[6] != '-')) {
       if (T[0] == 'X') {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[1] == T[4]) && (T[4] == T[7]) && (T[7] != '-')) {
       if (T[1] == 'X') {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[2] == T[5]) && (T[5] == T[8]) && (T[8] != '-')) {
       if (T[2] == 'X') {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[0] == T[4]) && (T[4] == T[8]) && (T[8] != '-')) {
       if (T[0] == 'X') {
         xWon = 1;
      } else {
         yWon = 1;
      }
   }
   if ((T[2] == T[4]) && (T[4] == T[6]) && (T[6] != '-')) {
       if (T[2] == 'X') {
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
      if (T[i] == '-') {
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
