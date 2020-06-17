from random import randint as rd

N = 15
with open("input.txt", "w") as fout:
    fout.write("1\n")
    fout.write(f"{N}\n")
    for i in range(N):
        fout.write(f"{rd(1, 10)} {rd(1, 20)}\n")
