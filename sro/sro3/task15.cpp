//
// Created by ybkuanysh on 2025/02/17.
//
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    bool notSorted;

    int arr[30];
    int seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution distribution(-100, 100);
    for (int &i: arr) {
        i = distribution(generator);
    }
    for (int i = 0; i < size(arr); i++) {
        notSorted = false;
        for (int j = 0; j < size(arr) - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                notSorted = true;
            }
        }
        if (notSorted == false) break;
    }
    for (int i: arr) {
        cout << i << " ";
    }
    return 0;
}
