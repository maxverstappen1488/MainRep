#include <iostream>
#include <iomanip>
using namespace std;

void random_massive(int** mass, int n, int m);
void manual_massive(int** mass, int n, int m);
void print_massive(int** mass, int n, int m);
void replacement(int** mass, int n, int m);
void insertion(int**& mass, int n, int& m);


int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n, m, input;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    // создание динамического массива
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    // выбор способа заполнения
    cout << "1-Случайная генерация чисел\n2-Ручной ввод чисел\n";
    cin >> input;

    // заполнение массива в зависимости от выбора
    switch (input) {
    case 1:
        random_massive(matrix, n, m);
        break;
    case 2:
        manual_massive(matrix, n, m);
        break;
    default:
        cout << "Ошибка ввода";
        // В случае ошибки ввода массив остается неинициализированным
    }
    print_massive(matrix, n, m);
    replacement(matrix, n, m);
    print_massive(matrix, n, m);
    insertion(matrix, n, m);
    print_massive(matrix, n, m);
}

void random_massive(int** mass, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mass[i][j] = rand() % 90 + 10;
        }
    }
}

void manual_massive(int** mass, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Введите значение для элемента " << i << " строки " << j << " столбца: ";
            cin >> mass[i][j];
        }
    }
}

void print_massive(int** mass, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(2) << mass[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void replacement(int** mass, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mass[i][j] % 2 == 1) {
                mass[i][j] = 0;
                break;
            }
        }
    }
}

void insertion(int**& mass, int n, int& m)
{
    int index = -1;
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (mass[i][j] == 0) {
                index = j;
                break;
            }
        }
        if (index != -1)
            break;
    }
    if (index == -1)
        return;
    int** result_matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        result_matrix[i] = new int[m + 1];
        for (int j = 0; j <= index; j++) {
            result_matrix[i][j] = mass[i][j];
        }
        result_matrix[i][index + 1] = mass[i][0];
        for (int j = index + 1; j < m; j++) {
            result_matrix[i][j + 1] = mass[i][j];
        }
    }
    delete[]mass;
    mass = result_matrix;
    m++;
}
