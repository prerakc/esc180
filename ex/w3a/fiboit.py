def fibo(n):
    fibNums = [1,1]
    
    for i in range(2,n+1):
        fibNums += [fibNums[i-1]+fibNums[i-2]]
    
    return fibNums[n]

print(fibo(4))