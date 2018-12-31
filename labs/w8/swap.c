int swap (int *a, int *b) {
   int arg1 = *a;
   int arg2 = *b;

   *a = arg2;
   *b = arg1;

   return 1;
}
