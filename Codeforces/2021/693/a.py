for _ in range(int(input())):
    w, h, n = map(int, input().split())
    x = 1
    while w % 2 == 0:
        x *= 2
        w >>= 1
    while h % 2 == 0:
        x *= 2
        h >>= 1
    print("YES" if x >= n else "NO")
