import sys
input = sys.stdin.buffer.readline
_ = int(input())
a = list(map(int, input().split()))
ans = 0
mx = 0
for i in range(2, max(a) + 1):
    c = 0
    for x in a:
        if x % i == 0:
            c += 1
    if c > mx:
        ans = i
        mx = c
print(ans)