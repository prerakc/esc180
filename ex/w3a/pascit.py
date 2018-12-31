def compress(L):
    accum = []
    for i in range(0,len(L)-1,1):
        accum += [L[i]+L[i+1]]
    return accum

def pasc(n):
    pascals = []
    
    for i in range(0,n):
        if i == 0:
            pascals += [[1]]
        elif i == 1:
            pascals += [[1,1]]
        else:
            pascals += [[1] + compress(pascals[i-1]) + [1]]
        
    return pascals

print(pasc(6))