import sys
input = sys.stdin.readline


for _ in range(int(input())):
    input()
    n, m = map(int, input().split())
    a = [tuple(map(int, input().split())) for _ in range(m)]
    a.sort(key=lambda x: x[1])
    l = [0, 0]
    for r, x in a:
        r -= 1
        if (x - l[r] - 1) % 2 == 0:
            l[r] = x
        elif x - l[r ^ 1] >= 2 and (x - l[r ^ 1] - 2) % 2 == 0:
            l[r] = x
            l[r ^ 1] = x - 1
        else:
            print("NO")
            break
    else:
        print("YES" if l[0] % 2 == l[1] % 2 else "NO")
