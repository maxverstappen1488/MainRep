#include <iostream>
using namespace std;
/**
* @brief вычисляет путь, пройденный лодкой по течению
* @param river_speed - cкорость течения реки
* @param boat_speed - cкорость лодки
* @param time - время пути
* @return - путь, пройденный лодкой
*/
double calculateL(const double river_speed, const double boat_speed, const double t);

/**
* @brief - точка входа в программу
* @return - 0, если программа выполнена корректно
*/
int main() {
    // скорость реки
    double river_speed = 0;
    // скорость лодки
    double boat_speed = 0;
    // время пути
    double t = 0;

    //вводим
    cout << "Введите скорость реки: ";
    cin >> river_speed;
    cout << "Введите скорость лодки: ";
    cin >> boat_speed;
    cout << "Введите время пути: ";
    cin >> t;

    //выводим
    cout << "Скорость реки: " << river_speed << endl;
    cout << "Скорость лодки: " << boat_speed << endl;
    cout << "Время пути: " << t << endl;

    //путь

    //формула: (river_speed + boat_speed) * t

    double L = calculateL(river_speed, boat_speed, t);

    //результат

    cout << "Путь: " << L << endl;
    return 0;
}
double calculateL(const double river_speed, const double boat_speed, const double t) {
    
    return (river_speed + boat_speed) * t;
}
