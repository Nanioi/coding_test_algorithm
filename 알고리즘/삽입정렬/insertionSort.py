#  방법1 - while + shift
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

#  방법2 - for + swap
def insertion_sort(arr):
    for i in range(1, len(arr)):
        for j in range(i,0,-1):
            if arr[j] < arr[j-1]:
                arr[j],arr[j-1] = arr[j-1],arr[j]
            else:
                break
    return arr
   

# 예시
data = [5, 2, 4, 6, 1, 3]
print("정렬 결과:", insertion_sort(data))
