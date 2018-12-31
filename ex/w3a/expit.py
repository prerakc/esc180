def exp(a,b):
    product = 1
    for i in range(0,b):
        product *= a
    return product

print(exp(4,3))