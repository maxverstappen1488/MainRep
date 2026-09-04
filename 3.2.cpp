#include <iostream>
#include <cmath>
#include <iomanip> // для setprecision
using namespace std;
/**
 * @brief Вычисляет сумму первых n членов последовательности (k = 0..n)
 * @param n Индекс последнего члена (n >= 0)
 * @return Сумма a_0 + a_1 + ... + a_n
 */
double calculate(const int n);

/**
 * @brief Вычисляет сумму членов последовательности, пока |член| >= e
 * @param e Точность (e > 0)
 * @return Сумма членов, модуль которых не меньше e
 */
double calculate_e(const double e);

int main() {
    setlocale(LC_ALL, "RU");
    int n{};            // верхняя граница для пункта а
    double e{};         // точность для пункта б

    // Ввод n с проверкой
    cout << "Введите n (верхний индекс суммы, n >= 1): ";
    cin >> n;
    if (cin.fail() || n < 1) {
        cout << "Ошибка! Введите целое положительное число: ";
        return 0;
    }

    // Ввод e с проверкой
    cout << "Введите e (точность, 0 < e < 1): ";
    cin >> e;
    if (cin.fail() || e <= 0.0 || e >= 1) {
        cout << "Ошибка! Введите положительное число: ";
        return 0;
    }

    double a = calculate(n);        // пункт а: сумма до индекса n
    double b = calculate_e(e);      // пункт б: сумма по точности

    cout << fixed << setprecision(10); // установим точность вывода
    cout << "\nОтвет на пункт а: " << a << endl;
    cout << "Ответ на пункт б: " << b << endl;

    return 0;
}


double calculate(const int n) {
    double current = 1.0;   // Это a_0 (при k=0)
    double sum = current;   // Начинаем сумму с a_0, так как ряд начинается с k=0
    // Цикл от k=1 до n. Используем size_t для счетчика.
    for (size_t i = 1; i <= (size_t)n; ++i) {
        // Рекуррентный переход для ряда (-1)^i / (2i)!
        // a_i = a_{i-1} * (-1) / (2i * (2i - 1))
        double di = (double)(i);
        current *= -1.0 / (2.0 * di * (2.0 * di - 1.0));
        //cout << i << ' ' << current << endl;
        sum += current;
    }
    return sum;
}


double calculate_e(const double e) {
    double sum = 0.0;
    double current = 1.0;   // Начинаем с a_0 = 1.0
    size_t i = 0;
    while (fabs(current) >= e) {
        sum += current; // Добавляем текущий член (сначала a_0, потом a_1 и т.д.)
        double di = (double)(i);
        // Вычисляем следующий член ряда, чтобы проверить его в условии while
        current *= -1.0 / (2.0 * di * (2.0 * di - 1.0));
        //cout << i << ' ' << current << endl;
        // Цикл продолжается, пока следующий член >= e и мы не превысили лимит итераций
        i++;
    }
    return sum;
}
