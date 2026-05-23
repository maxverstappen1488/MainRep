#include <iostream>
#include <cmath>
#include <iomanip> // для setprecision
using namespace std;


/**
 * @brief Вычисляет сумму первых n членов последовательности (k = 0..n)
 * @param n Индекс последнего члена (n >= 0)
 * @return Сумма a_0 + a_1 + ... + a_n
 */
double calculate(int n);

/**
 * @brief Вычисляет сумму членов последовательности, пока |член| >= e
 * @param e Точность (e > 0)
 * @return Сумма членов, модуль которых не меньше e
 */
double calculate_e(double e);

int main() {
    setlocale(0, "RU");

    int n{};            // верхняя граница для пункта а
    double e{};         // точность для пункта б

    // Ввод n с проверкой
    cout << "Введите n (количество членов, n >= 1): ";
    cin >> n;
    while (cin.fail() || n < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите целое положительное число: ";
        cin >> n;
    }

    // Ввод e с проверкой
    cout << "Введите e (точность, 1 < e > 0): ";
    cin >> e;
    while (cin.fail() || e <= 0.0||e>=1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите положительное число: ";
        cin >> e;
    }

    double a = calculate(n);        // пункт а: сумма до индекса n
    double b = calculate_e(e);      // пункт б: сумма по точности

    cout << fixed << setprecision(10); // установим точность вывода
    cout << "\nОтвет на пункт а: " << a << endl;
    cout << "Ответ на пункт б: " << b << endl;

    return 0;
}



double calculate(int n) {
    double current = 1.0;   // Это a_0 (при k=0)
    double sum = current;   // Начинаем сумму с первого члена

    for (int i = 1; i <= n; ++i) {
        // Рекуррентный переход: a_i = a_{i-1} * (-(i + 1) / i^2)
        double di = static_cast<double>(i);
        current *= -(di + 1.0) / (di * di);
        sum += current;
    }
    return sum;
}


double calculate_e(double e) {
    double sum = 0.0;
    double current = 1.0;   // Начинаем с a_0 = 1.0
    int i = 0;

    while (abs(current) >= e) {
        sum += current;
        i++;
        double di = static_cast<double>(i);
        current *= -(di + 1.0) / (di * di);

        if (i > 1000000) break;
    }
    return sum;
}

