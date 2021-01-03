def slope(x, y):
    return (y[1] - x[1]) / (y[0] - x[0])

n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))

ans = 0
for i in range(n):
    for j in range(i + 1, n):
        if abs(slope(a[i], a[j])) <= 1:
            ans += 1
print(ans)
