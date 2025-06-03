#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 5) / sqrt(4 - x*x);
}

double trapezoidal_integration(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return sum * h;
}

int main() {
    double a = 0.0;    
    double b = 2.0;    
    int n = 10000;     
    b = 1.999999;
    
    double result = trapezoidal_integration(a, b, n);
    
    cout << "Результат интегрирования методом трапеций: " 
         << setprecision(10) << result << endl;
    
    
    
    return 0;
}
