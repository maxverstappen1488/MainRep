#include <iostream> #include <cmath>
using namespace std;


double otr(const double a, const double b, const double c){
    int k=0;
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
double sum(const double a, const double b, const double c){
    return a+b+c;

}
int main(){
    double a = 0;
    double b = 0;
    double c = 0;
    
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Введите третье число: ";
    cin >> c;

    double K = otr(a, b, c);
    double S = sum(a, b, c);

    //выводим

    cout << "Количество отрицательных чисел: " << K << endl;
    cout << "Сумма чисел: " << S << endl;
    

    return 0;
}

