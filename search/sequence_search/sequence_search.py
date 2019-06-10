def sequence_search(arr, key):
    for idx, val in enumerate(arr):
        if val == key:
            return idx
    return -1
