from random import randint
from subprocess import PIPE, run
import sys


def create_input() -> str:
    maxn = 10
    maxa = 10
    n = randint(1, maxn)
    k = randint(1, n)
    s = str(n) + ' ' + str(k) + '\n'
    for _ in range(n):
        a = randint(1, maxa)
        s += str(a) + ' '
    s += '\n'
    return s


def input_p36() -> str:
    maxn = 8
    N = randint(2, maxn)
    s = str(N) + '\n'
    for _ in range(N):
        v = randint(1, 10)
        s += str(v) + ' '
    s += '\n'
    return s


__c: int = 0
while True:
    # create random input
    # print(__c)
    __c += 1
    s = input_p36()
    r1 = run(args=[sys.argv[1]],
             encoding='utf-8', input=s, stdout=PIPE).stdout
    r2 = run(args=[sys.argv[2]],
             encoding='utf-8', input=s, stdout=PIPE).stdout
    r3 = run(args=[sys.argv[3]],
             encoding='utf-8', input=s, stdout=PIPE).stdout
    if r1 != r3 and r2 != r3:
        print('Failed: test no.', __c, sep='')
        print('input:')
        print(s, end='')
        a = sys.argv[1].split('/')[-1]
        b = sys.argv[2].split('/')[-1]
        c = sys.argv[3].split('/')[-1]
        print(f'answer of {a}: ' + r1, end='')
        print(f'answer of {b}: ' + r2, end='')
        print(f'answer of {c}: ' + r3, end='')
        exit()
