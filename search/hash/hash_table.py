import random
init_size = 100

hash_table = [None] * init_size


def _hash(num):
    global hash_table
    return num % len(hash_table)


def search(num):
    location = _hash(num)
    start = location
    while hash_table[location] != None and hash_table[location] != num:
        location = collision(location)
        if start == location:
            return -1
    return -1 if hash_table[location] is None else location


def collision(location):
    location += 1
    location %= len(hash_table)
    return location


def insert(num):
    location = _hash(num)
    start = location
    while hash_table[location] != None:
        location += 1
        location %= len(hash_table)
        if start == location:
            print("哈希表已满")
            return
    hash_table[location] = num


def init_hash_table(arr):
    for each_num in arr:
        insert(each_num)


def main():
    arr = [random.randint(20, 100) for _ in range(20)]
    init_hash_table(arr)
