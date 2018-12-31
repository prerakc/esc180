import sys

def genSortKey(col,direction):
   def key(x):
      if direction == "+":
         return x[int(float(col))]
      else:
         return -x[int(float(col))]
   return key

def main():
   accum = []
   numCols = 0
   checkCols = True
   
   FIN=""
   FOUT=""
   COL=""
   DIR=""
   nargs=len(sys.argv)
   skip=False
   
   for i in range(1,nargs):
      if not skip:
         arg=sys.argv[i]
         print("INFO: processing",arg)
         
         if arg == "--fin":
            if i != nargs-1:
               FIN=sys.argv[i+1]
               skip=True
               
               try:
                  f=open(FIN,'r')
               except:
                  print("ERR: file",FIN,"is not present or can't be opened.")
                  return False
                  
               lines=f.readlines()
               f.close()
               
               for i in lines:
                  j=i.split('\n')[0]  # first get rid of the '\n'
                  k=j.split(',')      # now split on the comma
                  r=[]
                  for x in k:
                     if (checkCols):
                        numCols += 1
                        
                     r = r + [float(x)]
                     
                  checkCols = False
                  accum = accum + [r] # accumulate
                      
         elif arg == "--fout":
            if i != nargs-1:
               FOUT=sys.argv[i+1]
               skip=True
               
         elif arg == "--col":
            if i != nargs-1:
               COL=sys.argv[i+1]
               
               try:
                  col = float(COL)
               except:
                  print("Column input is not a number.")
                  return False
               
               if not(float(COL) in range(0,numCols,1)):
                  print("Not a valid column number.")
                  return False
                  
               skip=True
               
         elif arg == "--dir":
            if i != nargs-1:
               DIR=sys.argv[i+1]
               
               if not (DIR == "+" or DIR == "-"):
                  print("Invalid sorting direction.")
                  return False
               
               skip=True
               
         else:
            print("ERR: unknown arg:",arg)
            
      else:
         skip=False
         
   sortKey=genSortKey(COL,DIR)
   accum=sorted(accum, key=sortKey)    
   
   print("INFO: FIN",FIN)
   print("INFO: FOUT",FOUT)
   print("INFO: COL",COL)
   print("INFO: DIR",DIR)
   
   try:
      g=open(FOUT,'w')
   except:
      print("ERR: file",FIN,"can not be created for writing.")
      return False   
   
   for i in accum:
      output=""
      counter = 0
      
      for j in i:
         output += str(j)
         if counter != len(i)-1:
            output += ","
            counter += 1
            
      output += "\n"
      g.write(output)
      
   g.close()
   
   return True

main()