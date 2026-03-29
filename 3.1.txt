#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/**
 * @brief - вычисляет значение функции f(x) = √(1-x) - tan(x)
 * @param x - значение аргумента
 * @return - вычисленное значение функции
 *
 * @warning Область определения: x ≤ 1 (для корня) и x ≠ π/2 + π·n (для тангенса)
 */
double f(double x);

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
    double begin, end, delta;
    cout << "Input begin of range: ";
    cin >> begin;
    cout << "Input end of range: ";
    cin >> end;
    cout << "Input the interval: ";
    cin >> delta;

    // табулирование функции на заданном отрезке
    for (double x = begin; x <= end; x += delta) {
        cout << "x = " << setw(5) << x << "; y = " << f(x) << ";\n";
    }

    return 0;
}

double f(double x) {
    return sqrt(1 - x) - tan(x);
}