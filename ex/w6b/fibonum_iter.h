int genfibo (int n) {
   int i = 0;
   int a = 1;
   int b = 1;
   for (i = 0; i < n; i++) {
      int next = a+b;
      a = b;
      b = next;
   }
   return a;
}

