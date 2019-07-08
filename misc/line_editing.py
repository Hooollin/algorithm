# #代表退格，即删除上一个字符
# @代表清除此行

def line_editing(text):
    buffer = []
    res = ""
    for ch in text:
        if ch == '#' and len(buffer) != 0:
            buffer.pop()
        elif ch == '@':
            buffer = []
        else:
            buffer.append(ch)
            if ch == '\n':
                res += "".join(buffer)
                buffer = []
    res += "".join(buffer)
    print(res)