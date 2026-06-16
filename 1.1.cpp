#include <iostream>
#include <cmath>
using namespace std;

double calculateA(const double x, const double y, const double z) {
	return (pow(z, 2) * x + exp(-x) * cos(y * x)) / (y * x - exp(-x) * sin(y * x) + 1);
}

double calculateB(const double x, const double y, const double z) {
	return exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
}

int main()
{
	const double x = 0.3;
	const double y = 2.9;
	const double z = 0.5;

	double a = calculateA(x, y, z);
	double b = calculateB(x, y, z);

	cout << "a = " << a << endl << "b = " << b;

}
