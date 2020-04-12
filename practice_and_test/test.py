
def numOfWays(n: int) -> int:
    m = 1000000007
    sum1 = _pow(4, n - 1, m)
    sum2 = _pow(5, n - 1, m)
    return (sum1 + sum2) % m


def _mul(a, b, m):
    return a * b % m


def _pow(a, b, m):
    x = 6
    a %= m
    while b > 0:
        if b & 1:
            x = _mul(x, a, m)
        a = _mul(a, a, m)
        b >>= 1
    return x


print(numOfWays(7))
