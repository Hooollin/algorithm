def bubble_sort(arr, reverse=False):
    # 冒泡排序
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
                print_indicator(arr, i, j)
    if reverse:
        reverse_arr(arr)


def print_indicator(arr, i, j):
    print(arr)
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


def reverse_arr(arr):
    start, end = 0, len(arr) - 1
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1


def double_direction_bubble_sort(arr):
    front_index, end_index = 0, len(arr)
    finished = False
    while not finished and front_index < end_index:
        finished = True
        for i in range(front_index + 1, end_index):
            if arr[i] < arr[i - 1]:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
                finished = False
        end_index -= 1
        print(arr)
        for i in range(end_index - 1, front_index, -1):
            if arr[i] < arr[i - 1]:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
                finished = False
        front_index += 1
        print(arr)


bubble_sort([12, 3, 5, 2, 34, 2, 5, 6, 1, 3])
