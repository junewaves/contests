from random import randint

n = int(8e5)
m = int(1e9 - 1)
used = set()


def get():
    b = randint(0, m)
    while b in used:
        b = randint(0, m)
    used.add(b)
    return b


with open('input.txt', 'w') as fout:
    fout.write(f'{n}\n')
    for i in range(n):
        fout.write(f'{get()} ')
    fout.write('\n')
