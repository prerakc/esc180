def rule(val, L):
   sumL = 0
   for i in L:
      sumL += i
   if val == 1:
      if sumL == 2 or sumL == 3:
         return 1
      else:
         return 0
   else:
      if sumL == 3:
         return 1
      else:
         return 0
