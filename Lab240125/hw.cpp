//
// Created by ybkuanysh on 2025/01/31.
//
#include "iostream"
#include "random"
#include "iomanip"
#include "chrono"
#include "windows.h"

using namespace std;
using namespace chrono;

int main() {
    double array[14];
    int maxi, mini;

    int seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<double> d(-1.0, 10.0);
    for (int i = 0; i < size(array); i++) {
        array[i] = d(generator);
    }


    maxi = mini = 0;

    for (int i = 1; i < size(array); i++) {
        if (array[i] < array[mini]) mini = i;
        if (array[i] > array[maxi]) maxi = i;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Array initialized with numbers: " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    for (int i = 0; i < size(array); i++) {
        if (i == mini || i == maxi) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        } else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        cout << array[i] << " ";
    }
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "Total number of numbers between max and min: " << abs(maxi - mini)-1 << endl;

    return 0;
}
