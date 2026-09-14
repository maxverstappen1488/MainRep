#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief Вычисляет сумму ряда для sh(x) с заданной точностью eps через рекуррентное соотношение (итеративный подход)
 * @param x - значение аргумента
 * @param eps - точность вычисления
 * @return приближенное значение суммы ряда
 */
double calculate_sh(const double x, const double eps);

/**
 * @brief - точка входа в программу
 * @return 0, если программа выполнена корректно
 *
 * @details Программа табулирует функцию sh(x).
 * Для каждого значения x выводит:
 * - значение аргумента x
 * - точное значение функции sinh(x)
 * - приближённое значение через сумму ряда sumf(x, eps)
 * - фактическую разность между ними
 */
int main()
{
    setlocale(LC_ALL, "RU");
    // параметры табулирования
    double eps;
    cout << "Введите точность: ";
    cin >> eps;

    // Проверка корректности ввода точности
    if (eps >= 1 || eps <= 0) {
        cout << "Ошибка: точность должна быть в диапазоне (0; 1)." << endl;
        return 1;
    }

    double a, b, h; // ручной ввод интервала и шага
    cout << "Введите начало интервала: ";
    cin >> a;
    cout << "Введите конец интервала: ";
    cin >> b;
    cout << "Введите шаг табулирования: ";
    cin >> h;

    // вывод заголовка таблицы (ширина увеличена для 4 столбцов)
    cout << "--------------------------------------------------------------\n";
    cout << "|" << setw(13) << "argument" << "|"
        << setw(13) << "sinh(x)" << "|"
        << setw(13) << "sum of a row" << "|"
        << setw(13) << "difference" << "|\n";
    cout << "--------------------------------------------------------------\n";

    // основной цикл табулирования
    for (double x = a; x <= b + h / 2; x += h) { // +h/2 учёт погрешности double
        double exact_val = sinh(x);       // Точное значение (встроенная функция)
        double approx_val = calculate_sh(x, eps); // Значение по ряду с помощью рекуррентного соотношения
        
        double current_eps = eps;

        // Гарантируем, что разность строго меньше заданной точности eps
        while (fabs(exact_val - approx_val) >= eps) {
            current_eps /= 10.0; // Ужесточаем внутренний порог для ряда
            approx_val = calculate_sh(x, current_eps); // Пересчитываем ряд
        }

        double diff = fabs(exact_val - approx_val); // Погрешность
       
        // Вывод строки таблицы
        cout << "|" << setw(13) << x << "|"
            << setw(13) << exact_val << "|"
            << setw(13) << approx_val << "|"
            << setw(13) << diff << "|\n";
    }

    cout << "--------------------------------------------------------------\n";

    return 0;
}

double calculate_sh(const double x, const double eps) {
    double sum = 0.0;
    double current = x; // Первый член ряда при n = 0 (x^1 / 1!)
    int n = 0;

    // Суммируем, пока модуль текущего члена больше или равен точности
    while (fabs(current) >= eps) {
        sum += current;
        n++;
        // Рекуррентный переход: a_n = a_{n-1} * x^2 / ((2n) * (2n + 1))
        current = current * x * x / ((2.0 * n) * (2.0 * n + 1.0));
    }
    return sum;
}
