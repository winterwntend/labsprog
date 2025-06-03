import math

a = 1
b = 2

def func(x):
    return math.exp(-a * x) * math.cos(b * x)

def trapezoid_rule(func, a, b, nseg):
    dx = (b - a) / nseg
    sum_ = 0.5 * (func(a) + func(b))
    for i in range(1, nseg):
        sum_ += func(a + i * dx)
    return sum_ * dx


x0 = 0
x1 = 20 

eps = 1e-6
nseg = 2

int_1 = trapezoid_rule(func, x0, x1, nseg)
nseg *= 2
int_2 = trapezoid_rule(func, x0, x1, nseg)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = trapezoid_rule(func, x0, x1, nseg)
    nseg *= 2
    int_2 = trapezoid_rule(func, x0, x1, nseg)

print("Ответ: I =", int_2)
print("Количество разбиений:", nseg)
