x, y = 519, 865
while y != 0:
    t = x % y
    x = y
    y = t

print(x)
