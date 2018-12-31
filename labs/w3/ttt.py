from tttlib import *

T = genBoard()
printBoard(T)

while True:
   moveX = input("X move? ")
   
   while not((int(moveX) >= 0 and int(moveX) <= 8) and (T[int(moveX)] == 0)):
      moveX = input("Please enter a valid input for X. ")
   
   T[int(moveX)] = 1
   
   printBoard(T)
   state = analyzeBoard(T)
   
   if(state == 1):
      print("X won.")
      break
   elif(state == 3):
      print("Draw.")
      break
   elif(state == -1):
      print("Error.")
      break
   
   moveO = genWinningMove(T,2)
   if(moveO in range(0,9)):
      print("Winning Move of " + str(moveO))
      T[moveO] = 2
   else:
      print(str(moveO) + " No Winning Move")
      moveO = genNonLoser(T,2)
      if(moveO in range(0,9)):
         print("Non-losing Move of " + str(moveO))
         T[moveO] = 2
      else:
         print(str(moveO) + " No Non-losing Move")
         moveO = genRandomMove(T,2)
         print("Random Move of " + str(moveO))
         T[moveO] = 2

   printBoard(T)
   state = analyzeBoard(T)
   
   if(state == 2):
      print("O won.")
      break
   elif(state == 3):
      print("Draw.")
      break
   elif(state == -1):
      print("Error.")
      break   
