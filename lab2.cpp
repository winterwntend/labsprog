#include <iostream>
using namespace std;

// Класс вектора
class vect {
private:
    int dim;        // Размерность
    double* b;      // Элементы вектора
    int num;        // Уникальный номер
    static int count; // Общий счётчик

public:
    // Конструктор по умолчанию
    vect(int d = 1) : dim(d), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; i++) b[i] = 0;
        cout << "Вектор #" << num << " создан (размер " << dim << ")" << endl;
    }

    // Конструктор копирования
    vect(const vect& v) : dim(v.dim), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; i++) b[i] = v.b[i];
        cout << "Вектор #" << num << " скопирован из #" << v.num << endl;
    }

    // Деструктор
    ~vect() {
        delete[] b;
        cout << "Вектор #" << num << " удалён" << endl;
    }

    // Оператор присваивания
    vect& operator=(const vect& v) {
        if (this != &v) {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; i++) b[i] = v.b[i];
        }
        cout << "Вектор #" << num << " присвоен из #" << v.num << endl;
        return *this;
    }

    // Операторы векторной алгебры
    vect operator+(const vect& v) const {
        cout << "Сложение векторов #" << num << " и #" << v.get_num() << endl;
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = b[i] + v.b[i];
        return res;
    }

    vect operator-(const vect& v) const {
        cout << "Вычитание векторов #" << num << " и #" << v.get_num() << endl;
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = b[i] - v.b[i];
        return res;
    }

    vect operator-() const {
        cout << "Унарный минус для вектора #" << num << endl;
        vect res(dim);
        for (int i = 0; i < dim; i++) res.b[i] = -b[i];
        return res;
    }

    double operator*(const vect& v) const {
        cout << "Скалярное произведение векторов #" << num << " и #" << v.get_num() << endl;
        double sum = 0;
        for (int i = 0; i < dim; i++) sum += b[i] * v.b[i];
        return sum;
    }

    friend vect operator*(double k, const vect& v) {
        cout << "Умножение вектора #" << v.num << " на скаляр " << k << endl;
        vect res(v.dim);
        for (int i = 0; i < v.dim; i++) res.b[i] = k * v.b[i];
        return res;
    }

    // Оператор доступа по индексу
    double& operator[](int index) {
        return b[index];
    }

    // Константный оператор доступа по индексу
    const double& operator[](int index) const {
        return b[index];
    }

    // Метод для получения номера
    int get_num() const {
        return num;
    }

    void print() const {
        cout << "Вектор #" << num << ": [ ";
        for (int i = 0; i < dim; i++) cout << b[i] << " ";
        cout << "]" << endl;
    }
};

int vect::count = 0;

// Класс матрицы
class matr {
private:
    int dim;        // Размерность (квадратная)
    double* a;      // Элементы матрицы (по строкам)
    int num;        // Уникальный номер
    static int count; // Общий счётчик

public:
    // Конструктор по умолчанию
    matr(int d = 1) : dim(d), num(++count) {
        a = new double[dim * dim];
        for (int i = 0; i < dim * dim; i++) a[i] = 0;
        cout << "Матрица #" << num << " создана (размер " << dim << "x" << dim << ")" << endl;
    }

    // Конструктор копирования
    matr(const matr& m) : dim(m.dim), num(++count) {
        a = new double[dim * dim];
        for (int i = 0; i < dim * dim; i++) a[i] = m.a[i];
        cout << "Матрица #" << num << " скопирована из #" << m.num << endl;
    }

    // Деструктор
    ~matr() {
        delete[] a;
        cout << "Матрица #" << num << " удалена" << endl;
    }

    // Оператор присваивания
    matr& operator=(const matr& m) {
        if (this != &m) {
            delete[] a;
            dim = m.dim;
            a = new double[dim * dim];
            for (int i = 0; i < dim * dim; i++) a[i] = m.a[i];
        }
        cout << "Матрица #" << num << " присвоена из #" << m.num << endl;
        return *this;
    }

    // Операторы матричной алгебры
    matr operator+(const matr& m) const {
        cout << "Сложение матриц #" << num << " и #" << m.num << endl;
        matr res(dim);
        for (int i = 0; i < dim * dim; i++) res.a[i] = a[i] + m.a[i];
        return res;
    }

    matr operator-(const matr& m) const {
        cout << "Вычитание матриц #" << num << " и #" << m.num << endl;
        matr res(dim);
        for (int i = 0; i < dim * dim; i++) res.a[i] = a[i] - m.a[i];
        return res;
    }

    matr operator-() const {
        cout << "Унарный минус для матрицы #" << num << endl;
        matr res(dim);
        for (int i = 0; i < dim * dim; i++) res.a[i] = -a[i];
        return res;
    }

    matr operator*(const matr& m) const {
        cout << "Умножение матриц #" << num << " и #" << m.num << endl;
        matr res(dim);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                double sum = 0;
                for (int k = 0; k < dim; k++) {
                    sum += a[i * dim + k] * m.a[k * dim + j];
                }
                res.a[i * dim + j] = sum;
            }
        }
        return res;
    }

    friend matr operator*(double k, const matr& m) {
        cout << "Умножение матрицы #" << m.num << " на скаляр " << k << endl;
        matr res(m.dim);
        for (int i = 0; i < m.dim * m.dim; i++) res.a[i] = k * m.a[i];
        return res;
    }

    vect operator*(const vect& v) const {
        cout << "Умножение матрицы #" << num << " на вектор #" << v.get_num() << endl;
        vect res(dim);
        for (int i = 0; i < dim; i++) {
            double sum = 0;
            for (int j = 0; j < dim; j++) {
                sum += a[i * dim + j] * v[j];
            }
            res[i] = sum;
        }
        return res;
    }

    void print() const {
        cout << "Матрица #" << num << ":" << endl;
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << a[i * dim + j] << " ";
            }
            cout << endl;
        }
    }
};

int matr::count = 0;

// Основная функция
int main() {
    // Тестируем векторы
    vect v1(3), v2(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;
    
    v1 = v1 + v2;
    v1 = -v1;
    double dot = v1 * v2;
    vect v3 = 2.5 * v1;

    v1.print();
    v2.print();
    v3.print();
    cout << "Скалярное произведение: " << dot << endl;

    // Тестируем матрицы
    matr m1(2), m2(2);
    m1 = m1 + m2;
    m1 = -m1;
    matr m3 = m1 * m2;
    matr m4 = 3.0 * m1;

    // Умножение матрицы на вектор
    vect v4 = m1 * v1;

    return 0;
}
