import math

def func(x):
    return 1 / (x * math.sqrt(3 * x**2 - 2 * x - 1))

def trapezoid_rule(func, a, b, nseg):
    dx = (b - a) / nseg
    sum_ = 0.5 * (func(a) + func(b))
    for i in range(1, nseg):
        sum_ += func(a + i * dx)
    return sum_ * dx

a = 1.00001
b = 2
nseg = 2
eps = 1e-6

int_1 = trapezoid_rule(func, a, b, nseg)
nseg *= 2
int_2 = trapezoid_rule(func, a, b, nseg)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = trapezoid_rule(func, a, b, nseg)
    nseg *= 2
    int_2 = trapezoid_rule(func, a, b, nseg)

print(f"\nОтвет: I = {int_2}")
print(f"Количество разбиений: {nseg}")
