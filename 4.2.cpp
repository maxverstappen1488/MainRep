#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_mass(int* mass, int size);

void random_massive(int* mass, int size);

void manual_massive(int* mass, int size);

void last_elem(int* mass, int size);

void k(int** pointer_mass, int* size, int K);

int main()
{
    // настройка локали для поддержки русского языка
    setlocale(LC_ALL, "ru");

    // инициализация генератора случайных чисел текущим временем
    srand(time(0)); // генерация псевдослучайных чисел через время на ПК

    int n, input;

    // ввод размера массива
    cout << "Введите размер массива: ";
    cin >> n;

    // выбор способа заполнения
    cout << "1-Случайная генерация чисел\n2-Ручной ввод чисел\n";
    cin >> input;

    // создание динамического массива
    int* mass = new int[n];

    // заполнение массива в зависимости от выбора
    switch (input) {
    case 1:
        random_massive(mass, n);
        break;
    case 2:
        manual_massive(mass, n);
        break;
    default:
        cout << "Ошибка ввода";
        // В случае ошибки ввода массив остается неинициализированным
    }
    print_mass(mass, n);
    last_elem(mass, n);
    print_mass(mass, n);
    k(&mass, &n, -10);
    print_mass(mass, n);
}

// --- Реализация функций ---

void print_mass(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        cout << mass[i] << ' ';
    }
    cout << '\n';
}

void random_massive(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        // Генерация числа в диапазоне [-100, 100]
        mass[i] = rand() % 201 - 100;
        cout << mass[i] << ' ';
    }
}

void manual_massive(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите " << i << " элемент массива: ";
        cin >> mass[i];
    }
    print_mass(mass, size);
}

void last_elem(int* mass, int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (mass[i] % 3 == 0) {
            mass[i] = 0;
            break;
        }
    }
}

void k(int** pointer_mass, int* pointer_size, int K) {
    int size = *pointer_size;
    int* mass = *pointer_mass;
    int* k_mass = new int[size + 1];
    int index = -1;
    for (int i = size - 1; i >= 0; i--) {
        if (mass[i] % 2 == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) return;
    for (int i = 0; i <= index; i++) {
        k_mass[i] = mass[i];
    }
    k_mass[index + 1] = K;
    for (int i = index + 1; i < size; i++) {
        k_mass[i + 1] = mass[i];
    }
    delete[] mass;
    *pointer_size = size + 1;
    *pointer_mass = k_mass;
}