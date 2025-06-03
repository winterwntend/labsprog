#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return (1.0 / (x * x)) * sin(1.0 / x);
}

double trapezoid_rule(double (*func)(double), double a, double b, int nseg) {
    double dx = (b - a) / nseg;
    double sum = 0.5 * (func(a) + func(b));

    for (int i = 1; i < nseg; i++) {
        sum += func(a + i * dx);
    }

    return sum * dx;
}

int main() {
    cout << "Используем метод трапеций" << endl;
    cout << "Интегрируемая функция: f(x) = (1 / x^2) * sin(1 / x)" << endl;

    double a = 2.0 / M_PI;
    double b = 20.0; 
    int nseg = 2;
    double eps = 1e-6;

    cout << "a = " << a << " , b = " << b << " , eps = " << eps << endl;

    double int_1 = trapezoid_rule(func, a, b, nseg);
    nseg *= 2;
    double int_2 = trapezoid_rule(func, a, b, nseg);

    while (fabs(int_1 - int_2) > eps) {
        nseg *= 2;
        int_1 = trapezoid_rule(func, a, b, nseg);
        nseg *= 2;
        int_2 = trapezoid_rule(func, a, b, nseg);
    }

    cout << "\nОтвет: I = " << int_2 << "\nКоличество разбиений: " << nseg << endl;

    return 0;
}
