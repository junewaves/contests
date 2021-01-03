n = int(input())

s1 = set()
s2 = set()
for _ in range(n):
    s = input()
    if s[0] != '!':
        s1.add(s)
    else:
        s2.add(s[1:])
for s in s1:
    if s in s2:
        print(s)
        exit(0)
print('satisfiable')
