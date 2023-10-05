#include <iostream>
#include <cmath>
using namespace std;

double function(double x) {
    //место для функции
    return pow(2.718, x / 3) - 3 * log(x + 2);
}

double Horda(double aX, double aY, double bX, double bY) {
    //преобразуем (x-x1)/(x2-x1)=(y-y1)/(y2-y1) и выражаем х, при y = 0
    double x = (aX * bY - bX * aY) / (bY - aY);
    return x;
}

int main()
{
    int i = 0;
    double aX, bX, aY, bY, e, previousX;
    cin >> e;
    cin >> aX;
    cin >> bX; // bx неподвижная точка
    aY = function(aX);
    bY = function(bX);
    previousX = bX;

    while (abs(aX - previousX) > e) {
        previousX = aX;
        aX = Horda(aX, aY, bX, bY);
        aY = function(aX);
        i += 1;
    }

    cout << aX << endl;
    cout << i;
    return 1; // работает на промежутке -1.5 1. 1.5 - неподвижная
}