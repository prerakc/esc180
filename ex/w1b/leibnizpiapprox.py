def absvalue(n):
   if n >= 0:
      return n
   else:
      return -n

def LeibnizPi(n):
   accum = 0
   factor = -1
   for i in range(1,n+1,1):
      accum += factor*(1.0/(2*i+1))
      factor *= -1
   pi = 4*(accum+1)
   return pi

counter = 1
while (absvalue(LeibnizPi(counter) - 3.14159265) > 0.01):
   counter += 1
       
print(counter)