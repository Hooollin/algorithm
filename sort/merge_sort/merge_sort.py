import math
recursive_time = 0


def _merge_sort(arr, lo, hi):
    global recursive_time
    if lo < hi:
        recursive_time += 1
        mid = (lo + hi) // 2
        _merge_sort(arr, lo, mid)
        _merge_sort(arr, mid + 1, hi)
        merge(arr, lo, hi)


def merge(arr, lo, hi):
    t = arr[:]
    mid = (lo + hi) // 2
    i, j = lo, mid + 1
    k = lo
    while i <= mid and j <= hi:
        if t[i] < t[j]:
            arr[k] = t[i]
            i += 1
        else:
            arr[k] = t[j]
            j += 1
        k += 1
    while i <= mid:
        arr[k] = t[i]
        i += 1
        k += 1
    while j <= hi:
        arr[k] = t[j]
        j += 1
        k += 1


def merge_sort(arr):
    _merge_sort(arr, 0, len(arr) - 1)
    print(arr)


merge_sort([12, 3, 2, 2, 4, ])
print("recursive time: %d" % (math.ceil(recursive_time / 2)))
