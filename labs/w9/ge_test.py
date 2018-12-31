from ge import *

def printMatrix(matrix):
   for x in range(0, len(matrix),1):
      v = ""
      for j in range (0, len(matrix[0]), 1):
         v += str(matrix[x][j]) + "\t"
      print(v)
   print("-----------")

def main():
   eqns = [[1.0,2.0,3.0],[4.0,5.0,6.0],[7.0,8.0,9.0]]
   fw = ge_fw(eqns)
   bw = ge_bw(fw)

   printMatrix(eqns)
   printMatrix(fw)
   printMatrix(bw)

   print()

   eqns = [[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,0.0],[1.0,1.0,0.0,0.0]]
   fw = ge_fw(eqns)
   bw = ge_bw(fw)

   printMatrix(eqns)
   printMatrix(fw)
   printMatrix(bw)

   print()

   eqns = []
   fw = ge_fw(eqns)
   bw = ge_bw(fw)

   printMatrix(eqns)
   printMatrix(fw)
   printMatrix(bw)

   print()

   eqns = [[1.0,2.0,3.0,4.0],[5.0,6.0,7.0,8.0],[9.0,10.0,11.0,12.0]]
   fw = ge_fw(eqns)
   bw = ge_bw(fw)

   printMatrix(eqns)
   printMatrix(fw)
   printMatrix(bw)

   print()

   eqns = [[1.0,2.0,3.0],[4.0,5.0,6.0],[7.0,8.0,9.0],[10.0,11.0,12.0]]
   fw = ge_fw(eqns)
   bw = ge_bw(fw)

   printMatrix(eqns)
   printMatrix(fw)
   printMatrix(bw)

   print()

   eqns = 32
   fw = ge_fw(eqns)
   bw = ge_bw(fw)

   print(eqns)
   print(fw)
   print(bw)

main()
