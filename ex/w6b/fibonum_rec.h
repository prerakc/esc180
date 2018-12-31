int genfibo(int n)
{
   if (n == 0 || n == 1) 
   {
      return 1;
   } 
   else 
   {
      return genfibo(n-1)+genfibo(n-2);
   }    
}
