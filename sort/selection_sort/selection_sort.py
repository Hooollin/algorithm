def selection_sort(arr, reverse=False):
    for i in range(len(arr) - 1):
        minVal = arr[i]
        idx = i
        for j in range(i, len(arr)):
            if minVal > arr[j]:
                minVal = arr[j]
                idx = j
        arr[i], arr[idx] = arr[idx], arr[i]
    if reverse:
        reverse_arr(arr)


def reverse_arr(arr):
    start, end = 0, len(arr) - 1
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1
