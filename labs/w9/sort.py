def bubbleSort(array):
   if type(array) != list:
      return [False, array]

   for x in array:
      if type(x) != int:
         return [False, array]

   arr = list(array)
   n = len(arr)

   if n == 0:
      return [False, []]

   swapped = True

   while swapped:
      swapped = False
      for j in arr[1:n]:
         if arr[j-1] > arr[j]:
            temp = arr[j]
            arr[j] = arr[j-1]
            arr[j-1] = temp
            swapped = True

   return [True, arr]
