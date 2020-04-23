from random import randint
n = 10000
m = 9999
with open('input.txt', 'w') as o:
    o.write(str(n) + '\n')
    for _ in range(n):
        o.write(str(randint(1, 1e9-5)) + ' ')
    o.write('\n')
    o.write(str(m) + '\n')
    # o.write(f'{int(1e9 - 5)} {randint(1, 10)}\n')
    for _ in range(m):
        o.write(f'{randint(1, 1e9-5)} {randint(1, 2)}\n')
