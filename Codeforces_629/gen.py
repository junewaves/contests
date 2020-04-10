from random import randint
if __name__ == '__main__':
    n = 20
    with open('input.txt', 'w') as fout:
        fout.write(f'{n}\n')
        l = []
        for _ in range(n):
            l.append(randint(1, 5))
        for i in l:
            fout.write(f'{i} ')
