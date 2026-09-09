#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief - вычисляет значение функции гиперболического синуса: sh(x) = (e^x - e^-x) / 2
 * @param x - значение аргумента
 * @return - вычисленное значение функции
 */
double f(const double x);

/**
 * @brief - вычисляет сумму ряда для sh(x) с заданной точностью eps
 * @param x - значение аргумента
 * @param eps - точность вычисления (порог остановки)
 * @return - приближённое значение суммы ряда
 *
 * @details Использует рекурсивную вспомогательную функцию sumf_recursed().
 */
double sumf(const double x, const double eps);

/**
 * @brief - рекурсивная функция для вычисления суммы ряда
 * @param x - значение аргумента
 * @param eps - точность вычисления
 * @param n - текущий индекс члена ряда (начинается с 0)
 * @param prev_term - значение предыдущего члена ряда (для рекуррентной формулы)
 * @return - сумма текущего и последующих членов ряда
 *
 * @details Использует рекуррентную формулу для перехода между членами:
 * term_n = term_n-1 · x^2 / ((2n)·(2n+1))
 * Рекурсия останавливается, когда абсолютное значение члена становится меньше eps.
 */
double sumf_recursed(const double x, const double eps, const int n, const double prev_term);

/**
 * @brief - точка входа в программу
 * @return 0, если программа выполнена корректно
 *
 * @details Программа табулирует функцию sh(x) на отрезке [a; b] с шагом h.
 * Для каждого значения x выводит:
 * - значение аргумента x
 * - точное значение функции f(x) = sh(x)
 * - приближённое значение через сумму ряда sumf(x, eps)
 *
 * Вывод оформлен в виде таблицы с использованием setw() для выравнивания.
 */
int main()
{
    // допуск для сравнения вещественных чисел в условии цикла (не зависит от h)
    const double tol = 1e-9;

    // параметры табулирования
    double eps;
    cout << "Введите точность: ";
    cin >> eps;
    if (eps >= 1 || eps <= 0) {
        cout << "Точность от 0 до 1\n";
        return 1;
    }
    double a, b, h; //ручной ввод
    cout << "Введите начало интервала: ";
    cin >> a;
    cout << "Введите конец интервала: ";
    cin >> b;
    cout << "Введите шаг табулирования: ";
    cin >> h;

    // фиксированная точность вывода, чтобы столбцы function и sum of a row были сравнимы
    cout << fixed << setprecision(6);

    // вывод заголовка таблицы
    cout << "-------------------------------------------\n";
    cout << "|" << setw(13) << "argument" << "|"
        << setw(13) << "function" << "|"
        << setw(13) << "sum of a row" << "|\n";
    cout << "-------------------------------------------\n";

    // основной цикл табулирования
    for (double x = a; x <= b + tol; x += h) { // tol - защита от погрешности накопления double
        cout << "|" << setw(13) << x << "|"
            << setw(13) << f(x) << "|"
            << setw(13) << sumf(x, eps) << "|\n";
    }

    cout << "-------------------------------------------\n";

    return 0;
}

double f(const double x) {
    return (exp(x) - exp(-x)) / 2.0;
}

double sumf_recursed(const double x, const double eps, const int n, const double prev_term) {
    // Рекуррентная формула:
    // termₙ = term₋₁ * x² / ((2n)*(2n+1))
    // Для n=0 первый член равен x
    double term = (n == 0) ? x : prev_term * x * x / ((2 * n) * (2 * n + 1));

    // Базовый случай рекурсии: если член меньше eps, дальнейшее суммирование не нужно
    if (fabs(term) < eps) {
        return 0;
    }

    // Рекурсивный шаг: текущий член + сумма остальных
    return term + sumf_recursed(x, eps, n + 1, term);
}

double sumf(const double x, const double eps) {
    // Запуск рекурсии с начальными параметрами: n=0, prev_term=0
    return sumf_recursed(x, eps, 0, 0);
}
