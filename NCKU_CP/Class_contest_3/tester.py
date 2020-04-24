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
    maxn = 10
    n = randint(1, maxn)
    s = str(n) + '\n'
    for _ in range(n):
        s += '1 '
    s += '\n'


__c: int = 0
while True:
    # create random input
    print(__c, end='\r')
    __c += 1
    s = input_p36()
    r1 = run(args=[sys.argv[1]],
             encoding='utf-8', input=s, stdout=PIPE).stdout
    r2 = run(args=[sys.argv[2]],
             encoding='utf-8', input=s, stdout=PIPE).stdout
    if r1 != r2:
        print('input:')
        print(s, end='')
        a = sys.argv[1].split('/')[-1]
        b = sys.argv[2].split('/')[-1]
        print(f'answer of {a}: ' + r1, end='')
        print(f'answer of {b}: ' + r2, end='')
        exit()
    else:
        print('success', end='')
