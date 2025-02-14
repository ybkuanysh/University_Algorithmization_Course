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
    int array[30];
    int m = 45;

    int seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 100);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Array initialized with numbers: " << endl;
    int sum = 0, counter = 0;
    for (int i = 0; i < size(array); i++) {
        array[i] = distribution(generator);
        if (array[i] < m) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
            sum += array[i];
            counter++;
        } else { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); }
        cout << array[i] << " ";
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << endl << "Arithmetic mean is: " << sum / counter << endl;
}
