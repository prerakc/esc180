def fibo(n):
   if (n==0) or (n==1):
      return 1
   else:
      return fibo(n-1)+fibo(n-2)

def fiboL(n):
   L = []
   for i in range(0,n+1,1):
      L = L + [fibo(i)]
   return L

def redfibo(n):
   L = fiboL(n)
   return reduce(L)

def reducingMult(a,b):
   return a*b

def reduce(reducingMult,L):
   prodL = list(L)
   while len(prodL) > 1:
      a = prodL[0]
      b = prodL[1]
      prodAB = reducingMult(a,b)
      prodL = [prodAB] + prodL[2:len(L)]
   return int(prodL[0])