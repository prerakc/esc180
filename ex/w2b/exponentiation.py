def exp(a,b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    else:
        return a * exp(a,b-1)
    
print(exp(2,3))