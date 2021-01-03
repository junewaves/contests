n = int(input())
aoki = 0
taka = 0
votes = []
for _ in range(n):
    a, b = map(int, input().split())
    votes.append((a, b))
    aoki += a
votes.sort(reverse=True, key=lambda x: x[0]*2+x[1])
i = 0
while taka <= aoki:
    taka += sum(votes[i])
    aoki -= votes[i][0]
    i += 1
print(i)

