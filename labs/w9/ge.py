def ge_fw(matrix):
   if type(matrix) != list:
      return []

   if len(matrix) == 0:
      return []

   for s in range(0,len(matrix),1):
      for t in range(0,len(matrix[0]),1):
         if type(matrix[s][t]) != float:
            return []

   gauss = []
   for lists in matrix:
      gauss = gauss + [list(lists)]
   n = min(len(gauss), len(gauss[0]))

   for z in range(0,10,1):
      for i in range(0,n,1):
         # If first element of column is zero
         if gauss[i][i] == 0:
            # Find maximal entry in column
            maxEnt = abs(gauss[i][i])
            entRow = i
            for j in range(i+1,len(gauss),1):
               if abs(gauss[j][i]) > maxEnt:
                  maxEnt = abs(gauss[j][i])
                  entRow = j
            # Swap maximum row and current row
            tmp = list(gauss[i])
            gauss[i] = list(gauss[entRow])
            gauss[entRow] = tmp
         # Make all rows below this one 0 in current column
         for k in range(i+1,len(gauss),1):
            if gauss[k][i] != 0:
               factor = gauss[k][i]/gauss[i][i]
               for x in range(i,len(gauss[0]),1):
                  gauss[k][x] -= factor*gauss[i][x]
   
   return gauss

def ge_bw(matrix):
   if type(matrix) != list:
      return []

   if len(matrix) == 0:
      return []

   for s in range(0,len(matrix),1):
      for t in range(0,len(matrix[0]),1):
         if type(matrix[s][t]) != float:
            return []

   gauss = []
   for lists in matrix:
      gauss = gauss + [list(lists)]
   n = min(len(gauss),len(gauss[0]))

   for z in range(0,10,1):
      for i in range(n-1,-1,-1):
         # Find last nonzero row
         firstEnt = 0
         entRow = 0
         entCol = 0
         entFound = False
         j = i
         while ((j in range(0,i+1)) and (entFound == False)):
            for k in range(0,len(gauss[0]),1):
               if gauss[j][k] != 0:
                  firstEnt = gauss[j][k]
                  entRow = j
                  entCol = k
                  entFound = True
                  break
            j = j-1
       
         # Normalize row
         div = gauss[entRow][entCol]
         for m in range(0,len(gauss[0]),1):
            gauss[entRow][m] /= div
      
         # Make other values in column 0
         for x in range(entRow-1,-1,-1):
            factor = gauss[x][entCol]/gauss[entRow][entCol]
            for y in range(0,len(gauss[0]),1):
               gauss[x][y] -= factor*gauss[entRow][y]

   return gauss
