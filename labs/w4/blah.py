def fibo(n):
    if (n==0) or (n==1):
        return 1
    else:
        return fibo(n-1)+fibo(n-2)
    
def main():
    for i in range(0,10):
        print(fibo(i))
        
main()