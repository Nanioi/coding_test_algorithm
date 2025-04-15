import random

data_list = random.sample(range(100), 50)

def bubble_sort(data):
    n = len(data)
    for i in range(n):
        swap = False
        for j in range(0, n - i - 1):
            if data[j] > data[j+1]:
                data[j],data[j+1] = data[j+1],data[j]
                swap = True
        if not swap:
            break
    return data

print("정렬 전 데이터: ", data_list)
print("정렬 후 데이터: ", bubble_sort(data_list))


            