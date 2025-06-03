import math

def func(x):
    return math.exp(-2 * x) * math.sin(2 * x)

def trapezoid_rule(func, a, b, nseg):
    dx = (b - a) / nseg
    sum = 0.5 * (func(a) + func(b))
    
    for i in range(1, nseg):
        sum += func(a + i * dx)
    
    return sum * dx

print("Используем метод трапеций")
print("Интегрируемая функция: f(x) = exp(-2x) * sin(2x)")

a = 0
b = 20  
nseg = 2
eps = 1e-6

print(f"a = {a}, b = {b}, eps = {eps}")

int_1 = trapezoid_rule(func, a, b, nseg)
nseg *= 2
int_2 = trapezoid_rule(func, a, b, nseg)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = trapezoid_rule(func, a, b, nseg)
    nseg *= 2
    int_2 = trapezoid_rule(func, a, b, nseg)

print(f"\nОтвет: I = {int_2}\nКоличество разбиений: {nseg}")
