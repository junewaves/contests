import io,os
inp = io.BytesIO(os.read(0,os.fstat(0).st_size)).readlines()
for tc in range(1, int(inp[0]) + 1):
    a = [0, 0]
    for i, x in enumerate(sorted(map(int, inp[tc << 1].split()), reverse=True)):
        if i & 1 == x & 1:
            a[i & 1] += x
    if a[0] == a[1]:
        print("Tie")
    elif a[0] > a[1]:
        print("Alice")
    else:
        print("Bob")

