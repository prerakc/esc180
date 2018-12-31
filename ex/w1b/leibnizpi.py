def LeibnizPi(n):
   accum = 0
   factor = -1
   for i in range(1,n+1,1):
       accum += factor*(1.0/(2*i+1))
       factor *= -1
   pi = 4*(accum+1)
   return pi

print(LeibnizPi(99))
        