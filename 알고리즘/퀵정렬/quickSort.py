# pivot - arr[0] 기준
def quickSort(arr):
    if len(arr) <= 1:
        return arr
    left, right = list(), list()
    pivot = arr[0]
    
    for i in range(1,len(arr)):
        if pivot > arr[i]:
            left.append(arr[i])
        else: 
            right.append(arr[i])
    
    return quickSort(left) + [pivot] + quickSort(right)


# list comprehension 사용
def quickSort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[0]
    left = [item for item in arr[1:] if pivot > item ]
    right = [item for item in arr[1:] if pivot <= item ]
    
    return quickSort(left) + [pivot] + quickSort(right)


# pivot - arr[len(arr)//2] 기준
def quickSort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [item for item in arr if item < pivot]
    middle = [item for item in arr if item == pivot]
    right = [item for item in arr if item > pivot]
    
    return quickSort(left) + middle + quickSort(right)