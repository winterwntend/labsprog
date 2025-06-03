#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
    return x * x;
}

double trapezoidal_integration(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += func(x);
    }
    
    return sum * h;
}

int main() {
    double a = 0.0;  
    double b = 1.0;  
    int n = 100;     
    
    double result = trapezoidal_integration(a, b, n);
    
    cout << "Результат интегрирования методом трапеций: " 
         << setprecision(10) << result << endl;
    cout << "Точное значение для сравнения: " << 1.0/3.0 << endl;
    
    return 0;
}
