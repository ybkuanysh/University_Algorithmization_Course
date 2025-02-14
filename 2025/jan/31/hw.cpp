//
// Created by ybkuanysh on 2025/01/31.
//
#include <iostream>
#include <random>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace chrono;

int main() {
    double array[10];
    double S = 5.0;
    int indexOfLast = 0;

    int seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(-100.0, 100.0);

    double lastLength = 0.0;
    for (int i = 0; i < size(array); i++) {
        array[i] = distribution(generator);
        if (lastLength < abs(array[i] - S)) {
            lastLength = abs(array[i] - S);
            indexOfLast = i;
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Array initialized with numbers: " << endl;
    for (int i = 0; i < size(array); i++) {
        if (i == indexOfLast) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        } else { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); }
        cout << array[i] << " ";
    }
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "Length: " << lastLength << " index: " << indexOfLast << " value: " << array[indexOfLast] << endl;
}
