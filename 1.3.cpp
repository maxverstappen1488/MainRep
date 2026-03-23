#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief - подсчитывает количество отрицательных чисел
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return - количество отрицательных чисел
 */
double otr(const double a, const double b, const double c);

/**
 * @brief - вычисляет сумму трех чисел
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return - сумма чисел
 */
double sum(const double a, const double b, const double c);


/**
 * @brief - точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(){
    // ввод
    double a = 0;
    double b = 0;
    double c = 0;
    
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Введите третье число: ";
    cin >> c;

    // вычисления
    double K = otr(a, b, c);
    double S = sum(a, b, c);

    // вывод
    cout << "Количество отрицательных чисел: " << K << endl;
    cout << "Сумма чисел: " << S << endl;
    

    return 0;
    
}
double sum(const double a, const double b, const double c){
    return a+b+c;
}

double otr(const double a, const double b, const double c){
    double k=0;
    if (a < 0){
        k=k+1;
    }
    if (b < 0){
        k=k+1;
    }
    if (c < 0){
        k=k+1;
    }
    return k;

}
