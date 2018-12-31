def compress(L):
    if len(L) == 1:
        return [1]
    else:
        accum = []
        for i in range(0,len(L),1):
            if i == 0:
                accum += [L[i] + L[i+1]]
            elif i == len(L)-1:
                accum += [L[i] + L[i-1]]
            else:
                accum += [L[i-1] + L[i] + L[i+1]]
        return accum
    
def trinomial(n):
    if n == 0:
        return [1]
    else:
        return [1] + compress(trinomial(n-1)) + [1]
    
print(trinomial(4))
    