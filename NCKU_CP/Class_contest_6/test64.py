a = 19194342495775
c = int(2e12)
n, *z = list(map(int, open(0)))
for b in z:
    print((a * b - 1) // c + 1)
