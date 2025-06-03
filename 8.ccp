#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return log(x) / (x * x);
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
    cout << "Используем метод трапеций\n";
    cout << "Интегрируемая функция: f(x) = ln(x) / x^2\n";

    double a = 1, b = 1000;
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
