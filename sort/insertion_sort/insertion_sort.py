def insertion_sort(arr, reverse=False):
    for i in range(len(arr)):
        t = arr[i]
        for j in range(i):
            if t < arr[j]:
                for k in range(j, i):
                    arr[k + 1] = arr[k]
                arr[j] = t
                break
    if reverse:
        reverse_arr(arr)


def reverse_arr(arr):
    start, end = 0, len(arr) - 1
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1
