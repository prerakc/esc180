def fibonacciNumber(n):
    if(n == 0):
        return 0
    elif((n == 1) or (n == 2)):
        return 1
    else:
        return fibonacciNumber(n-1) + fibonacciNumber(n-2)
    
print(fibonacciNumber(10))