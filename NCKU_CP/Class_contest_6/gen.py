from random import randint

with open("input.txt", "w") as fo:
    fo.write("10000\n")
    for _ in range(10000):
        fo.write(f"{randint(1, 2000000)}\n")
