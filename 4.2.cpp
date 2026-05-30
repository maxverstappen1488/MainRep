#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_mass(const int* mass, const size_t size);

void random_massive(int* mass, const size_t size);

void manual_massive(int* mass, const size_t size);

void last_elem(int* mass, const size_t size);

void k(int** pointer_mass, size_t* pointer_size, const int K);

int main()
{
    // настройка локали для поддержки русского языка
    setlocale(LC_ALL, "ru");

    // инициализация генератора случайных чисел текущим временем
    srand(time(0)); // генерация псевдослучайных чисел через время на ПК

    size_t n;
    int input;

    // ввод размера массива
    cout << "Введите размер массива: ";
    if (!(cin >> n) || n == 0) {
        cerr << "Ошибка: введите целое число > 0" << endl;
        return 0;
    }

    // выбор способа заполнения
    cout << "1-Случайная генерация чисел\n2-Ручной ввод чисел\n";
    if (!(cin >> input) || (input != 1 && input != 2)) {
        cerr << "Ошибка: выберите 1 или 2" << endl;
        return 0;
    }

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
        return 0;
        // В случае ошибки ввода массив остается неинициализированным
    }
    print_mass(mass, n);
    last_elem(mass, n);
    print_mass(mass, n);
    k(&mass, &n, -10);
    print_mass(mass, n);
    delete[] mass;
    return 0;
}

// --- Реализация функций ---

void print_mass(const int* mass, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << mass[i] << ' ';
    }
    cout << '\n';
}

void random_massive(int* mass, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        // Генерация числа в диапазоне [-100, 100]
        mass[i] = rand() % 201 - 100;
    }
}

void manual_massive(int* mass, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << "Введите " << i << " элемент массива: ";
        cin >> mass[i];
    }
}

void last_elem(int* mass, const size_t size) {
    for (size_t i = size; i-- > 0;) {
        if (mass[i] % 3 == 0) {
            mass[i] = 0;
            break;
        }
    }
}

void k(int** pointer_mass, size_t* pointer_size, const int K) {
    size_t size = *pointer_size;
    int* mass = *pointer_mass;
    int* k_mass = new int[size + 1];
    size_t index = size;
    for (size_t i = size; i-- > 0;) {
        if (mass[i] % 2 == 0) {
            index = i;
            break;
        }
    }
    if (index == size) {
        delete[]k_mass;//чтобы не было утечки
        return;
    }
    for (size_t i = 0; i <= index; i++) {
        k_mass[i] = mass[i];
    }
    k_mass[index + 1] = K;
    for (size_t i = index + 1; i < size; i++) {
        k_mass[i + 1] = mass[i];
    }
    delete[] mass;
    *pointer_size = size + 1;
    *pointer_mass = k_mass;
}
