# kmp implement in python


def build_prefix_table(pattern):
    """
    创建最长公共前后缀表
    """
    prefix = [0] * len(pattern)
    i = 1
    length = 0
    while i < len(pattern):
        if pattern[i] == pattern[length]:
            length += 1
            prefix[i] = length
            i += 1
        else:
            if length == 0:
                prefix[i] = length
                i += 1
            else:
                length = prefix[length - 1]
    return prefix


def shift_prefix(prefix):
    """
    将最长前缀表整体向后移一位，在首位填-1
    """
    for i in range(len(prefix) - 1, 0):
        prefix[i] = prefix[i - 1]
    prefix[0] = -1


def kmp(text, pattern):
    """
    匹配
    """
    prefix_table = build_prefix_table(pattern)
    shift_prefix(prefix_table)
    i = 0
    j = 0
    while i < len(text):
        if j == len(pattern) - 1 and pattern[j] == text[i]:
            print("found pattern at : %d" % (i - j))
            j = 0
            i += 1
        if pattern[j] == text[i]:
            i += 1
            j += 1
        else:
            if j != -1:
                j = prefix_table[j]
            else:
                i += 1
                j += 1


kmp("ABABABABBAA", "ABABA")
