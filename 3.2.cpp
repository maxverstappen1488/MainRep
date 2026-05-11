#include <iostream>
#include <cmath>
#include <iomanip> // для setprecision
using namespace std;

/**
 * @brief - вычисляет k-й член последовательности через константу
 * @param k - индекс члена последовательности
 * @return - значение члена: (-1)^k · (1+k) / k!
 *
 * @details Использует рекуррентное соотношение:
 * f(0) = 1
 * f(k) = f(k-1) * (-(k+1) / (k*k)) для k >= 1
 */
double function(int k);

/**
 * @brief - вычисляет сумму членов последовательности от k до n
 * @param k - начальный индекс
 * @param n - конечный индекс
 * @return - сумма членов последовательности
 */
double calculate(int k, int n);

/**
 * @brief - вычисляет сумму членов последовательности, пока |член| >= e
 * @param k - начальный индекс
 * @param e - пороговое значение (точность)
 * @return - сумма членов, удовлетворяющих условию
 */
double calculate_e(double e);

int main() {
    setlocale(0, "RU");

    int k_start = 0;  // стартовый индекс последовательности
    int n{};            // верхняя граница для пункта а
    double e{};         // точность для пункта б

    cout << "Введите n: " << endl;
    cin >> n;
    cout << "Введите e: " << endl;
    cin >> e;

    double a = calculate(k_start, n);        // пункт а: сумма до n
    double b = calculate_e(e);      // пункт б: сумма по точности

    cout << fixed << setprecision(10); // установим точность вывода
    cout << "\nОтвет на пункт а: " << a << endl;
    cout << "Ответ на пункт б: " << b << endl;

    return 0;
}

/**
 * @brief - вычисляет k-й член последовательности через рекуррентное соотношение
 */
double function(int k) {
    if (k == 0) {
        return 1.0;
    }

    double prev = 1.0; //начинаем с f(0)
    for (int i = 1; i <= k; ++i) {
        prev = prev * (-(static_cast<double>(i + 1)) / (static_cast<double>(i) * i));
    }
    return prev;
}

/**
 * @brief - вычисляет сумму членов последовательности от k до n
 */
double calculate(int k, int n) {
    double sum = 0;
    double member;
    for (int i = k; i <= n; i++) {
        member = function(i);
        sum += member;
    }
    return sum;
}

/**
 * @brief - вычисляет сумму членов последовательности, пока |член| >= e
 */
double calculate_e(double e) {
    double sum = 0;
    double member;
    int current_k = 0;

    // Вычисляем первый член
    member = function(current_k);

    while (fabs(member) >= e) {
        sum += member;
        current_k++;
        member = function(current_k); // вычисляем следующий член
    }
    return sum;
}
