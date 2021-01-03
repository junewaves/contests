import sys
input = sys.stdin.readline

class segtree:
    def __init__(self, n):
        self.n = n
        self.t = [0] * (2 * n)
    def add(self, l, r, x):
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                self.t[l] += x
                l += 1
            if r & 1:
                r -= 1
                self.t[r] += x
            l >>= 1
            r >>= 1
    def __getitem__(self, idx):
        idx += self.n
        ret = 0
        while idx:
            ret += self.t[idx]
            idx >>= 1
        return ret

n = int(input())
e1 = [-1] * (n - 1)
e2 = [-1] * (n - 1)
adj = [[] for _ in range(n)]
for i in range(n - 1):
    e1[i], e2[i] = map(lambda x: int(x) - 1, input().split())
    adj[e1[i]].append(e2[i])
    adj[e2[i]].append(e1[i])
T = 0
ts = [-1] * n
te = [-1] * n
stk = [(0, -1)]
while stk:
    u, p = stk.pop()
    if p != -2:
        ts[u] = T
        T += 1
        stk.append((u, -2))
        for v in adj[u]:
            if v != p:
                stk.append((v, u))
    else:
        te[u] = T
st = segtree(n)
for _ in range(int(input())):
    t, e, x = map(int, input().split())
    u, v = e1[e - 1], e2[e - 1]
    if t == 2:
        u, v = v, u
    if ts[u] < ts[v]:
        st.add(0, n, x)
        st.add(ts[v], te[v], -x)
    else:
        st.add(ts[u], te[u], x)
ans = [0] * n
for i in range(n):
    ans[i] = st[ts[i]]
print(*ans, sep='\n')
