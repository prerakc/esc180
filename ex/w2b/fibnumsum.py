def fibonacciNumber(n):
    if(n == 0):
        return 0
    elif((n == 1) or (n == 2)):
        return 1
    else:
        return fibonacciNumber(n-1) + fibonacciNumber(n-2)

def fibNumSum(n):
    sumNum = 0
    
    for i in range(0,n+1,1):
        sumNum += fibonacciNumber(i)
            
    return sumNum

print(fibNumSum(10))