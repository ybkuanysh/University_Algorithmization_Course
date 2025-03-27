//
// Created by ybkuanysh on 2025/03/27.
//
#include <iostream>

using namespace std;

void decimalToBaseN(int num, int base) {
    if (num == 0) return;

    int remainder = num % base;
    decimalToBaseN(num / base, base);

    if (remainder < 10)
        cout << remainder;
    else
        cout << char('A' + remainder - 10);
}

int main() {
    int number, base;

    cout << "Введите число: ";
    cin >> number;

    cout << "Введите систему счисления (2-16): ";
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "Ошибка: основание должно быть от 2 до 16!" << endl;
        return 1;
    }

    cout << "Число в " << base << "-ричной системе: ";
    if (number == 0)
        cout << "0";
    else
        decimalToBaseN(number, base);

    cout << endl;
    return 0;
}