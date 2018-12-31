def exp(a,b):
   product = 1
   cnt = 0

   while True:
      if cnt < b:
         product *= a
         cnt += 1
      else:
         break

   return product

print(exp(2,4))
print(exp(4,2))
