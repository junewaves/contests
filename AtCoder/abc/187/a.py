a, b = input().split()
def digit_sum(s):
    return sum(map(int, s))
print(max(digit_sum(a), digit_sum(b)))
