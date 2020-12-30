from random import randint

with open("input.txt", "w") as fo:
    fo.write("500000\n")
    for i in range(500000):
        fo.write(f"{randint(2, 1e7)} ")
