art = int(input())
print((art//26) * 'z', end = '')
print('' if art%26 == 0 else "abcdefghijklmnopqrstuvwxyz"[art%26 -1])