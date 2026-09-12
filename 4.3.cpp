#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief Перечисление способов заполнения массива
 */
enum filling_method { random = 1, manual };

/**
 * @brief Заполняет массив случайными числами в диапазоне [10, 99]
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void random_massive(int** mass, const size_t n, const size_t m);

/**
 * @brief Заполняет массив числами, введёнными пользователем
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void manual_massive(int** mass, const size_t n, const size_t m);

/**
 * @brief Выводит элементы массива на экран
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void print_massive(const int* const* mass, const size_t n, const size_t m);

/**
 * @brief Находит первый нечётный элемент в каждой строке и заменяет его на 0
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void replacement(int** mass, const size_t n, const size_t m);

/**
 * @brief Вставляет столбец после первого столбца, содержащего 0
 * @param mass - ссылка на указатель на массив (для изменения размера)
 * @param n - количество строк
 * @param m - ссылка на количество столбцов (изменяется при вставке)
 * @note Если нулевых элементов нет, массив не изменяется
 */
void insertion(int**& mass, const size_t n, size_t& m);

/**
 * @brief Проверяет корректность введённого значения
 * @param input - ссылка на введённое значение для проверки
 * @note Завершает программу при вводе неположительного числа
 */
void input_check(int& input);

int main()
{
    setlocale(LC_ALL, "RU");
    size_t n=0, m=0;
    int input;
    cout << "Введите количество строк: ";
    void input_check(int& input);
    n = input;
    cout << "Введите количество столбцов: ";
    void input_check(int& input);
    m = input;
    
    // создание динамического массива
    int** matrix = new int* [n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    // выбор способа заполнения
    cout << random<<"-Случайная генерация чисел\n"<<manual<<" - Ручной ввод чисел\n";
    cin >> input;

    // заполнение массива в зависимости от выбора
    switch (input) {
    case random:
        random_massive(matrix, n, m);
        break;
    case manual:
        manual_massive(matrix, n, m);
        break;
    default:
        cout << "Ошибка ввода";
        // В случае ошибки ввода массив остается неинициализированным
        // освобождаем память при ошибке
        for (size_t i = 0; i < n; i++) delete[] matrix[i];
        delete[] matrix;
        return 1;
    }
    print_massive(matrix, n, m);
    replacement(matrix, n, m);
    print_massive(matrix, n, m);
    insertion(matrix, n, m);
    print_massive(matrix, n, m);
    // Освобождение памяти в конце
    for (size_t i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}


/**
 * @brief Заполняет массив случайными числами в диапазоне [10, 99]
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void random_massive(int** mass, const size_t n, const size_t m) {
    if (mass == nullptr) //проверка, что не пустой указатель
        return;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            mass[i][j] = rand() % 90 + 10;
        }
    }
}


/**
 * @brief Заполняет массив числами, введёнными пользователем
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void manual_massive(int** mass, const size_t n, const size_t m) {
    if (mass == nullptr)//проверка, что не пустой указатель
        return;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << "Введите значение для элемента " << i << " строки " << j << " столбца: ";
            cin >> mass[i][j];
        }
    }
}

/**
 * @brief Выводит элементы массива на экран
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void print_massive(const int* const* mass, const size_t n, const size_t m)
{
    if (mass == nullptr)//проверка, что не пустой указатель
        return;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << setw(2) << mass[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief Находит первый нечётный элемент в каждой строке и заменяет его на 0
 * @param mass - указатель на массив
 * @param n - количество строк
 * @param m - количество столбцов
 */
void replacement(int** mass, const size_t n, const size_t m)
{
    if (mass == nullptr)//проверка, что не пустой указатель
        return;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (mass[i][j] % 2 == 1) {
                mass[i][j] = 0;
                break;
            }
        }
    }
}

/**
 * @brief Вставляет столбец после первого столбца, содержащего 0
 * @param mass - ссылка на указатель на массив (для изменения размера)
 * @param n - количество строк
 * @param m - ссылка на количество столбцов (изменяется при вставке)
 * @note Если нулевых элементов нет, массив не изменяется
 */
void insertion(int**& mass, const size_t n, size_t& m)
{
    if (mass == nullptr)//проверка, что не пустой указатель
        return;
    size_t index = m;
    for (size_t j = m; j-- > 0; ) {
        for (size_t i = 0; i < n; i++) {
            if (mass[i][j] == 0) {
                index = j;
                break;
            }
        }
        if (index != m)
            break;
    }
    if (index == m)
        return;
    int** result_matrix = new int* [n];
    for (size_t i = 0; i < n; i++) {
        result_matrix[i] = new int[m + 1];
        for (size_t j = 0; j <= index; j++) {
            result_matrix[i][j] = mass[i][j];
        }
        result_matrix[i][index + 1] = mass[i][0];
        for (size_t j = index + 1; j < m; j++) {
            result_matrix[i][j + 1] = mass[i][j];
        }
        delete[] mass[i];
    }
    delete[]mass;
    mass = result_matrix;
    m++;
}

/**
 * @brief Проверяет корректность введённого значения
 * @param input - ссылка на введённое значение для проверки
 * @note Завершает программу при вводе неположительного числа
 */
void input_check(int& input) {
    cin >> input;
    if (input <= 0) { //количество строк или столбцов не может быть отрицательным или равным нулю
        cout << "Ошибка ввода";
        exit(1);
    }
}
