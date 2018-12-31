def compress(L):
    accum = []
    for i in range(0,len(L)-1,1):
        accum += [L[i] + L[i+1]]
    accum += [L[len(L)-1]*2]
    return accum

def bernoulli(n):
    if n == 0:
        return [1]
    else:
        return [1] + compress(bernoulli(n-1))
    
print(bernoulli(5))