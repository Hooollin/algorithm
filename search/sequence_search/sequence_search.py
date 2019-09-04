def sequence_search(arr, key):
    for idx, val in enumerate(arr):
        if val == key:
            return idx
    return -1


def pivot_sequence_search(arr, key):
    t = arr[0]
    arr[0] = key
    i = len(arr) - 1
    while arr[i] != key:
        i -= 1
    return 0 if t == 0 else -1 if i == 0 else i
