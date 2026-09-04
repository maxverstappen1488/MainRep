#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits> // Подключение библиотеку для numeric_limits

using namespace std;

/**
 * @brief - вычисляет значение функции f(x) = √(1-x) - tan(x)
 * @param x - значение аргумента
 * @return - вычисленное значение функции
 *
 * @warning Область определения: x ≤ 1 (для корня) и x ≠ π/2 + π·n (для тангенса)
 */
double f(const double x);

/**
 * @brief - точка входа в программу
 * @return 0, если программа выполнена корректно
 *
 * @details Программа табулирует функцию f(x) = √(1-x) - tan(x)
 * на заданном пользователем отрезке [begin, end] с шагом delta.
 * Результаты выводятся в формате: "x = значение; y = значение;"
 *
 * @note Для форматированного вывода используется setw(5) из <iomanip>
 */
int main()
{
    // ввод параметров табулирования
    double begin = 0, end = 0, delta = 0;
    cout << "Input begin of range: ";
    if (!(cin >> begin)) {
        cout << "Ошибка ввода\n";
        return 1;
    }

    cout << "Input end of range: ";
    if (!(cin >> end)) {
        cout << "Ошибка ввода\n";
        return 1;
    }

    cout << "Input the interval: ";
    if (!(cin >> delta) || delta <= 0) {
        cout << "Шаг должен быть положительным числом\n";
        return 1;
    }

    if (begin > end) {
        cout << "Начало отрезка не может быть больше конца\n";
        return 1;
    }

    // количество шагов считаем целым числом, чтобы не копить погрешность
    int n = (int)((end - begin) / delta + 0.5);

    cout << fixed << setprecision(4);

    // Получаем встроенное значение машинного эпсилон для удобства чтения кода
    const double eps = numeric_limits<double>::epsilon();

    // табулирование функции на заданном отрезке
    for (int i = 0; i <= n + eps; ++i) {
        double x = begin + i * delta;

        cout << "x = " << setw(8) << x << "; y = ";
        // ООФ: x > 1 (с учетом машинной погрешности) или cos(x) ≈ 0 (тангенс не определен)
        if (x > 1 + eps || fabs(cos(x)) < eps) { 
            cout << "Outside the domain of the function";
        }
        else {
            cout << setw(8) << f(x);
        }
        cout << ";\n";
    }

    return 0;
}

double f(const double x) {
    return sqrt(1 - x) - tan(x);
}
