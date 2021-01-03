n, m = map(int, input().split())
dp = [n] * (1 << n) 
adj = [[False] * n for _ in range(n)]
for i in range(n):
    adj[i][i] = True
for _ in range(m):
    u, v = map(lambda x: int(x) - 1, input().split())
    adj[u][v] = True
    adj[v][u] = True
for mask in range(1, 1 << n):
    l = []
    for i in range(n):
        if (mask >> i) & 1:
            l.append(i)
    for a in l:
        for b in l:
            if not adj[a][b]:
                break
        else:
            continue
        break
    else:
        dp[mask] = 1
        continue
    sub = (mask - 1) & mask
    while sub:
        dp[mask] = min(dp[mask], dp[sub] + dp[mask ^ sub])
        sub = (sub - 1) & mask
print(dp[-1])

