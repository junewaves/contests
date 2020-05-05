from random import randint

with open("input.txt", "w") as fo:
    fo.write("100000 1\n")
    for i in range(100000):
        fo.write(f"{randint(1, 100)} ")
    fo.write("\n")
