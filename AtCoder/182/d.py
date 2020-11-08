import sys
input = sys.stdin.buffer.readline

_ = int(input())
a = list(map(int, input().split()))
pos = 0
pre = 0
mxe = 0
ans = 0
for x in a:
    pre += x
    mxe = max(mxe, pre)
    ans = max(ans, pos + mxe)
    pos += pre
print(ans)