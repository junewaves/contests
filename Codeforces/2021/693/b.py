for _ in range(int(input())):
    n = int(input())
    a1, a2 = 0, 0
    for i in map(int, input().split()):
        if i == 1:
            a1 += 1
        else:
            a2 += 1
    if a1 % 2 or (a2 % 2 and a1 < 2):
        print("NO")
    else:
        print("YES")
