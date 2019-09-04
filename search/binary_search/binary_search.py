# arr内的元素必须有序
def binary_search(arr, key):
    # 保证有序
    arr = sorted(arr)
    return binary_search_core_iterative(arr, key, 0, len(arr))


def binary_search_core_recursive(arr, key, lo, hi):
    if lo < hi:
        mid = lo + (hi - lo) // 2
        if arr[mid] < key:
            lo = mid + 1
            return binary_search_core_recursive(arr, key, lo, hi)
        elif arr[mid] > key:
            hi = mid - 1
            return binary_search_core_recursive(arr, key, lo, hi)
        else:
            return mid
    else:
        return -1


def binary_search_core_iterative(arr, key, lo, hi):
    mid = lo + (hi - lo) // 2
    while lo < hi:
        if arr[mid] == key:
            return mid
        elif arr[mid] > key:
            hi = mid - 1
            mid = lo + (hi - lo) // 2
        else:
            lo = mid + 1
            mid = lo + (hi - lo) // 2
    return -1
