from math import exp, fabs

def func(x):
    return x**2 * exp(-x)

def trapezoid_rule(func, a, b, nseg):
    dx = (b - a) / nseg
    sum_ = 0.5 * (func(a) + func(b))
    for i in range(1, nseg):
        sum_ += func(a + i * dx)
    return sum_ * dx

a = 0
b = 1  
nseg = 2
eps = 1e-6

int_1 = trapezoid_rule(func, a, b, nseg)
nseg *= 2
int_2 = trapezoid_rule(func, a, b, nseg)

while fabs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = trapezoid_rule(func, a, b, nseg)
    nseg *= 2
    int_2 = trapezoid_rule(func, a, b, nseg)

print("Ответ: I =", int_2)
print("Количество разбиений:", nseg)
