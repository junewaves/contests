from random import randint
import subprocess

maxn = 10
maxa = 10
c = 0
while True:
    # create random input
    print(c)
    c += 1
    n = randint(1, maxn)
    k = randint(1, n)
    s = str(n) + ' ' + str(k) + '\n'
    for i in range(n):
        a = randint(1, maxa)
        s += str(a) + ' '
    s += '\n'
    res = subprocess.run(args=['bin/p37_fix.exe'], input=s, text=True, capture_output=True)
    res2 = subprocess.run(args=['bin/p39_test.exe'], input=s, text=True, capture_output=True)
    if res.stdout != res2.stdout:
        print('input:')
        print(s, end='')
        print('answer of dp: ' + res.stdout, end='')
        print('answer of greedy: ' + res2.stdout, end='')
        exit()
