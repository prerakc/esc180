def sumList(x):
    if len(x) == 0:
        return 0
    elif len(x) == 1:
        return x[0]
    else:
        return x[0] + sum(x[1:len(x)])

print(sumList([1,2,3]))