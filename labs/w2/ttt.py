from tttlib import *

T = genBoard()

while True:
   printBoard(T)
      
   moveX = input("X move? ")
   
   while not((moveX >= 0 and moveX <= 8) and (T[int(moveX)] == 0)):
      moveX = input("Please enter a valid input for X. ")
   
   T[int(moveX)] = 1
      
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

   printBoard(T)
   
   moveO = input("O move? ")
   
   while not((moveO >= 0 and moveO <= 8) and (T[int(moveO)] == 0)):
      moveO = input("Please enter a valid input for O. ")
   
   T[int(moveO)] = 2
      
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