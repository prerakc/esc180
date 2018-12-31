def genBoard():
    board = [0,0,0,0,0,0,0,0,0]
    
    return board

def printBoard(T):
    if(type(T) != list):
        return False
    
    if(len(T) != 9):
        return False
    
    for element in T:
        if(type(element) != int):
            return False
        else:
            if not(element in range(0,3,1)):
                return False
    
    board = T
    positions = genBoard()
    
    for i in range(0,9,1):
        if(board[i] == 0):
            positions[i] = i
        elif(board[i] == 1):
            positions[i] = "X"
        else:
            positions[i] = "O"
    
    posNum = 0
    
    for j in range(0,5,1):
        if(j % 2 == 0):
            print(" " + str(positions[posNum]) + " " + "|" + " " + str(positions[posNum+1]) + " " + "|" + " " + str(positions[posNum+2]) + " ")
            posNum += 3
        else:
            print("---|---|---")
            
    return True

def analyzeBoard(T):
    numX = 0
    numO = 0
    
    if(type(T) != list):
        return -1
    
    if(len(T) != 9):
        return -1
    
    for element in T:
        if(type(element) != int):
            return -1
        else:
            if not(element in range(0,3,1)):
                return -1
            else:
                if(element == 1):
                    numX += 1
                elif(element == 2):
                    numO += 1
    
    if((numX-numO > 1) or (numO-numX > 1)):
        return -1
    
    board = T
    
    xWon = False
    yWon = False
    
    if(board[0] == board[1] and board[1] == board[2]):
        if(board[0] == 1):
            xWon = True
        elif(board[0] == 2):
            yWon = True
    if(board[3] == board[4] and board[4] == board[5]):
        if(board[3] == 1):
            xWon = True
        elif(board[3] == 2):
            yWon = True   
    if(board[6] == board[7] and board[7] == board[8]):
        if(board[6] == 1):
            xWon = True
        elif(board[6] == 2):
            yWon = True
    if(board[0] == board[3] and board[3] == board[6]):
        if(board[0] == 1):
            xWon = True
        elif(board[0] == 2):
            yWon = True     
    if(board[1] == board[4] and board[4] == board[7]):
        if(board[1] == 1):
            xWon = True
        elif(board[1] == 2):
            yWon = True    
    if(board[2] == board[5] and board[5] == board[8]):
        if(board[2] == 1):
            xWon = True
        elif(board[2] == 2):
            yWon = True            
    if(board[0] == board[4] and board[4] == board[8]):
        if(board[0] == 1):
            xWon = True
        elif(board[0] == 2):
            yWon = True     
    if(board[2] == board[4] and board[4] == board[6]):
        if(board[2] == 1):
            xWon = True
        elif(board[2] == 2):
            yWon = True
    
    if((xWon == True) and (yWon == False)):
        return 1
    elif((xWon == False) and (yWon == True)):
        return 2
    elif((xWon == True) and (yWon == True)):
        return -1
    else:
        stillPlaying = False
        
        for i in range(0,9,1):
            if(board[i] == 0):
                stillPlaying = True
                break
        
        if(stillPlaying):
            return 0
        else:
            return 3
