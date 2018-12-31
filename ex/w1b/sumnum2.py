def sum(n):
    accum = 0
    factor = -1
    for i in range(0,n+1,1):
        accum += factor*i
        factor *= -1
    return accum

print(sum(5))
    