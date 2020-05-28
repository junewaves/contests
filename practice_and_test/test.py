from random import randint as rd

with open("input.txt", "w") as fo:
    fo.write(f"5 10\n")
    for i in range(1, 5):
        for j in range(i, 6):
            fo.write(f"{i} {j} {rd(1, 100)}\n")
