def absvalue(n):
   if n >= 0:
      return n
   else:
      return -n

def squareroot(n,a):
   estimate = n/2

   while True:
      if absvalue(n-estimate*estimate) > a:
         estimate = (estimate+n/estimate)/2
      else:
         break

   return estimate

print(squareroot(25,0.0000000001))
print(squareroot(47,0.0000000001))
