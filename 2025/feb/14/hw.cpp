//
// Created by ybkuanysh on 2025/02/14.
//
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <windows.h>

using namespace std;
using namespace chrono;

int main() {

  {
    int n = 5;
    int arr[n][n];
    int seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution distribution(-100, 100);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        arr[i][j] = distribution(generator);
      }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i][n-1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Задача Глазунова страница 66 номер 15: " << sum << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == n - 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << setw(4) << arr[i][j];
      }
      cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
  }

  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Задача Златопольский 12.24 Б: " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    int arr[6][6];
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        arr[i][j] = j + i + 1 > 6 ? j + i - 5 : j + i + 1;
      }
    }

    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
