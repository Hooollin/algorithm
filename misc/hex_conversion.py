def hex_conversion(n, hex=2):
    # 使用stack划分了不同的关注层次，避免去考虑数组的下标等细节问题
    s = []
    while n:
        s.append(n % hex)
        n //= hex
    while len(s):
        print(s.pop(),end="")

