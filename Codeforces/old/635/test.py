import math

for i in range(1000, 2000):
    y = x = i
    for j in range(2, 17):
        m = n = j
        ans = (x >> n) + math.ceil(10.0 * (2.0 - pow(2, -(n - 1))))
        b = True
        while n > 0:
            x = x // 2 + 10
            n -= 1
            if x == 20 and n > 0:
                b = False
                break
        if not b:
            break
        if x // 10 != ans // 10:
            print(y, m, x, ans)
