import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort(reverse=True)
    a, b = 0, 0
    for i, x in enumerate(l):
        if i % 2 and x % 2:
            b += x
        elif i % 2 == 0 and x % 2 == 0:
            a += x
    if a == b:
        print("Tie")
    elif a > b:
        print("Alice")
    else:
        print("Bob")

