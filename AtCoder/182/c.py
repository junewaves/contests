s = input()
digit_sum = 0
cnt = [0] * 3
for c in s:
    x = ord(c) - 48
    cnt[x % 3] += 1
    digit_sum += x
digit_sum %= 3
ans = -1
if digit_sum == 0:
    ans = 0
elif digit_sum == 1:
    if cnt[1] >= 1 and len(s) >= 2:
        ans = 1
    elif cnt[2] >= 2 and len(s) >= 3:
        ans = 2
else:
    if cnt[2] >= 1 and len(s) >= 2:
        ans = 1
    elif cnt[1] >= 2 and len(s) >= 3:
        ans = 2

print(ans)