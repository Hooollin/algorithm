def shell_sort(arr):
    d = len(arr) // 2
    while d > 0:
        for i in range(d + 1, len(arr)):
            if arr[i - d] > arr[i]:
                t = arr[i]
                j = i - d
                while j >= 0:
                    if arr[j] > t:
                        arr[j + d] = arr[j]
                    else:
                        break
                    j -= d
                arr[j + d] = t
                print(arr)
                print_indicator(arr, j + d, i)
        d = d // 2


def print_indicator(arr, i, j):
    output_str = " "
    for idx, num in enumerate(arr):
        length = len(str(num))
        if idx != i and idx != j:
            output_str += " " * length
        else:
            output_str += " " * (length // 2)
            output_str += "^"
            output_str += " " * (length - length // 2 - 1)
        output_str += "  "
    print(output_str)


shell_sort([1, 2, 3, 5, 6, 1, 2, 4, 2, 23, 5, 6, 2, 5, 3, ])
