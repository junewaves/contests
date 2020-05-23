from math import *

pi = acos(-1)
a, b, c, d = [float(x) for x in input().split()]
x1 = a * cos(c * pi / 6 + d * pi / 360)
y1 = a * sin(c * pi / 6 + d * pi / 360)
x2 = b * cos(d * pi / 30)
y2 = b * sin(d * pi / 30)
a1 = (x2 - x1) ** 2
a2 = (y2 - y1) ** 2
print(sqrt(a1 + a2))
