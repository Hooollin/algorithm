def build_max_heap(arr):
    arr.insert(0, 0)
    for i in range(len(arr) // 2, 0, -1):
        heapify_down(arr, i)
    del arr[0]
    return arr


def heapify_down(arr, k):
    t = arr[k]
    for i in range(k * 2, len(arr)):
        if i < len(arr) - 1 and arr[i] < arr[i + 1]:
            i += 1
        if t >= arr[i]:
            break
        else:
            arr[k] = arr[i]
            k = i
        i *= 2
    arr[k] = t


def heap_sort(arr):
    res = []
    t = arr[0:]
    _len = len(arr)
    for i in range(_len):
        t = build_max_heap(t)
        res.append(t[0])
        t = t[1:]

    print(res)


heap_sort([1, 2, 4, 5, 3])
