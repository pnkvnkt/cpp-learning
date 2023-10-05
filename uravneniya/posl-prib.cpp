#include <iostream>
#include <cmath>
using namespace std;

double function(double x) {
    //место для функции
    return 0.3 * (pow(2.718, x / 3) - 3 * log(x + 2)) + x;
}

double f(double* aX, double* aY) {
    double bX = *aY;
    *aY = function(bX);
    *aX = bX;
    return 1;
}

double modul(double a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int main()
{
    int i = 0;
    double aX, bX, aY, e, previousX;
    cin >> e;
    cin >> aX;
    cin >> bX;
    aY = function(aX);
    previousX = bX;

    while (abs(aX - previousX) > e) {
        previousX = aX;
        f(&aX, &aY);
        i += 1;
    }

    cout << aX << endl;
    cout << i;
    return 1;
}