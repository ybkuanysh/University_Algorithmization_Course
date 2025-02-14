//
// Created by ybkuanysh on 2025/02/02.
//
/*
    Даны числа A1, B1, C1, A2, B2, C2. Напечатать координаты
    точки пересечения прямых, описываемых уравнениями
    A1*X + B1*Y + C1 = 0
    A2*X + B2*Y + C2= 0
    либо сообщить, что эти прямые совпадают,
    не пересекаются либо вообще не существуют
 */
#include <iostream>

// #define USER_INPUT
#define CODE_INPUT

using namespace std;

int main() {
#ifdef CODE_INPUT
    double A1 = 3, B1 = 1, C1 = 8;
    double A2 = 4, B2 = 2, C2 = 5;
#endif

#ifdef USER_INPUT
    cout << "Please enter A1, B1, C1 for line equation:" << endl;
    double A1, B1, C1;
    cin >> A1 >> B1 >> C1;

    cout << "Please enter A2, B2, C2 for line equation:" << endl;
    double A2, B2, C2;
    cin >> A2 >> B2 >> C2;
#endif
    double x, y;

    if (A1 / A2 == B1 / B2 && A1 / A2 == C1 / C2) {
        cout << "the lines coincide" << endl;
        return 0;
    }

    if ((A1 == 0.0 && B1 == 0.0) || (A2 == 0.0 && B2 == 0.0)) {
        cout << "One of the lines does not exist" << endl;
        return 0;
    }

    if (A1 / A2 != B1 / B2) {
        x = (B1 * C2 - C1 * B2) / (A1 * B2 - A2 * B1);
        y = -(C2 + A2 * x) / B2;

        cout << "The lines intersect at point: \n X = " << x << "\n Y = " << y << endl;
    } else {
        cout << "Algorith error" << endl;
    }

    return 0;
}
