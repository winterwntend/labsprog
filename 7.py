import math

def f(x):
    return x**5 / math.sqrt(4 - x**2)

def trapezoidal_integration(a, b, n):
    h = (b - a) / n
    total = 0.5 * (f(a) + f(b))

    for i in range(1, n):
        x = a + i * h
        total += f(x)

    return total * h

a = 0.0
b = 2.0
n = 10000
b = 1.999999  

result = trapezoidal_integration(a, b, n)

print(f"Результат интегрирования методом трапеций: {result:.10f}")
