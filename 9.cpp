#include <iostream>
#include <cmath>

using namespace std;

double a = 1.0;
double b = 2.0;

double func(double x) {
    return exp(-a * x) * cos(b * x);
}

double trapezoid_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

int main() {
    double x0 = 0.0;
    double x1 = 20.0; 
    double eps = 1e-6;
    int n = 2;

    double int_1 = trapezoid_rule(func, x0, x1, n);
    n *= 2;
    double int_2 = trapezoid_rule(func, x0, x1, n);

    while (fabs(int_1 - int_2) > eps) {
        int_1 = int_2;
        n *= 2;
        int_2 = trapezoid_rule(func, x0, x1, n);
    }

    cout << "Ответ: I = " << int_2 << endl;
    cout << "Количество разбиений: " << n << endl;

    return 0;
}
