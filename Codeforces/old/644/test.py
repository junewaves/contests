from random import randint as rd
import subprocess

ext1 = ['/home/samchen/code/contests/bin/pD']
ext2 = ['/home/samchen/code/contests/bin/pD_2']

while True:
    _in = '1\n{} {}'.format(rd(1, 1e9), rd(1, 1e9)).encode('utf-8')

    res1 = subprocess.run(ext1, stdout=subprocess.PIPE, input=_in)
    res2 = subprocess.run(ext2, stdout=subprocess.PIPE, input=_in)
    if res1.stdout != res2.stdout:
        print("input: ", _in.decode('utf-8'))
        print("output 1:", res1.stdout.decode('utf-8'))
        print("output 2:", res2.stdout.decode('utf-8'))
        break
