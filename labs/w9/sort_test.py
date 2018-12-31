from sort import *

def main():
   arr = [0,5,8,6,9,1,3,2,4,7]
   print("INPUT:")
   print(arr)
   print("FUNCTION OUTPUT:")
   output = bubbleSort(arr)
   print(output)

   print()

   arr = 34
   print("INPUT:")
   print(arr)
   print("FUNCTION OUTPUT:")
   output = bubbleSort(arr)
   print(output)

   print()

   arr = [0.0,5,8,6,9,1,3,2,4,7]
   print("INPUT:")
   print(arr)
   print("FUNCTION OUTPUT:")
   output = bubbleSort(arr)
   print(output)

   arr = []
   print("INPUT:")
   print(arr)
   print("FUNCTION OUTPUT:")
   output = bubbleSort(arr)
   print(output)

main()
