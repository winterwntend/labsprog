import math

def func(x):
    return x * x

def trapezoidal_integration(a, b, n):
    h = (b - a) / n
    total = 0.5 * (func(a) + func(b))

    for i in range(1, n):
        x = a + i * h
        total += func(x)

    return total * h

a = 0.0
b = 1.0
n = 100

result = trapezoidal_integration(a, b, n)

print(f"Результат интегрирования методом трапеций: {result:.10f}")
print(f"Точное значение для сравнения: {1.0 / 3.0:.10f}")
