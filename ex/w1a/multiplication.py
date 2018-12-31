def mult(a,b):
   sum = 0  
   cnt = 0

   while True:
      if cnt < b: 
         sum += a 
         cnt += 1
      else:
         break

   return sum

print(mult(4,3))
print(mult(3,4))      
