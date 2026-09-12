#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief Перечисление способов создания массива
 */
enum create_mass { random = 1, manual };

/**
 * @brief Выводит элементы массива на экран
 * @param mass - указатель на массив
 * @param size - размер массива
 */
void print_mass(const int* mass, const size_t size);

/**
 * @brief Заполняет массив случайными числами в диапазоне [-100, 100]
 * @param mass - указатель на массив
 * @param size - размер массива
 */
void random_massive(int* mass, const size_t size);

/**
 * @brief Заполняет массив числами, введёнными пользователем
 * @param mass - указатель на массив
 * @param size - размер массива
 */
void manual_massive(int* mass, const size_t size);

/**
 * @brief Находит последний элемент, делящийся на 3, и заменяет его на 0
 * @param mass - указатель на массив
 * @param size - размер массива
 */
void last_elem(int* mass, const size_t size);

/**
 * @brief Вставляет число K после первого чётного элемента массива
 * @param pointer_mass - указатель на указатель массива (для изменения размера)
 * @param pointer_size - ссылка на размер массива (изменяется при вставке)
 * @param K - число для вставки
 * @note Если чётных элементов нет, массив не изменяется
 */
int main()
{
    // настройка локали для поддержки русского языка
    setlocale(LC_ALL, "ru");

    // инициализация генератора случайных чисел текущим временем
    srand(time(0)); // генерация псевдослучайных чисел через время на ПК

    size_t n;
    long long input;

    // ввод размера массива
    cout << "Введите размер массива: ";
    if (!(cin >> input) || input <= 0) {
        cerr << "Ошибка: введите целое число > 0" << endl;
        return 0;
    }

    n = (size_t)input;

    // выбор способа заполнения
    cout << create_mass::random << "-Случайная генерация чисел\n" << create_mass::manual << "-Ручной ввод чисел\n";
    if (!(cin >> input) || (input != create_mass::random && input != create_mass::manual)) {
        cerr << "Ошибка: выберите 1 или 2" << endl;
        return 0;
    }

    // создание динамического массива
    int* mass = new int[n];

    // заполнение массива в зависимости от выбора
    switch (input) {
    case create_mass::random:
        random_massive(mass, n);
        break;
    case create_mass::manual:
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
    size_t counter = 0;
    for (size_t i = n; i-- > 0;) {
        if (mass[i] % 2 == 0) {
            counter++;
        }
    }

    int* k_mass = new int[n + counter];
    
    for (size_t i = 0, k = 0; i < n; i++) {
        k_mass[k++] = mass[i];
        if (mass[i] % 2 == 0) {
			k_mass[k++] = -10; // вставка числа K после чётного элемента
        }
    }
	delete[] mass; //удаляем старый массив, чтобы не было утечки памяти
    n++;
    mass = k_mass; //на место старого массива записываем адрес нового массива
    print_mass(mass, n);
	delete[]k_mass; //удаляем новый массив, чтобы не было утечки памяти
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
