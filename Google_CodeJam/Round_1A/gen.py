from random import randint

with open("input.txt", "w") as fout:
    r = 5000
    fout.write("1\n")
    fout.write(f"{r} {r}\n")
    for i in range(r):
        for j in range(r):
            fout.write(f"{randint(1, 10)} ")
        fout.write("\n")
