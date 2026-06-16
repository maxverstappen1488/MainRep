#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief - подсчитывает количество отрицательных чисел среди трёх входных значений
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return - количество отрицательных чисел (0, 1, 2 или 3)
 * 
 * @details Функция последовательно проверяет каждое из трёх чисел на условие < 0.
 * Для каждого отрицательного числа счётчик увеличивается на 1.
 */
double otr(const double a, const double b, const double c);

/**
 * @brief - вычисляет сумму трёх чисел
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return - сумма входных значений (a + b + c)
 */
double sum(const double a, const double b, const double c);

/**
 * @brief - точка входа в программу
 * @return 0, если программа выполнена корректно
 * 
 * @details Программа запрашивает у пользователя три числа, затем:
 * - вызывает функцию otr() для подсчёта количества отрицательных чисел;
 * - вызывает функцию sum() для вычисления суммы введённых чисел;
 * - выводит результаты на экран.
 */
int main() {
    // инициализация переменных
    double a = 0;
    double b = 0;
    double c = 0;

    // ввод данных от пользователя
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Введите третье число: ";
    cin >> c;

    // вычисления
    double K = otr(a, b, c);
    double S = sum(a, b, c);

    // вывод результатов
    cout << "Количество отрицательных чисел: " << K << endl;
    cout << "Сумма чисел: " << S << endl;

    return 0;
}

/**
 * @brief - подсчитывает количество отрицательных чисел среди трёх входных значений
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return - количество отрицательных чисел (0, 1, 2 или 3)
 */
double otr(const double a, const double b, const double c) {
    int k = 0;
    if (a < 0) {
        k = k + 1;
    }
    if (b < 0) {
        k = k + 1;
    }
    if (c < 0) {
        k = k + 1;
    }
    return k;
}

/**
 * @brief - вычисляет сумму трёх чисел
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return - сумма входных значений (a + b + c)
 */
double sum(const double a, const double b, const double c) {
    return a + b + c;
}
