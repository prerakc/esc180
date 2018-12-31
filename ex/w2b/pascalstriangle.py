def compress(L):
    if len(L) <= 1:
        return []
    else:
        accum = []
        for i in range(0,len(L)-1,1):
            accum += [L[i] + L[i+1]]
        return accum

def pasc(n):
    if(n == 0):
        return [1]
    else:
        return [1] + compress(pasc(n-1)) + [1]
    
print(pasc(0))
print(pasc(1))
print(pasc(2))
print(pasc(3))
print(pasc(4))