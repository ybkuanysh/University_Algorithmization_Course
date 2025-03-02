//
// Created by ybkuanysh on 2025/03/02.
//
// 21. В двумерном массиве целых чисел размерности 5*9 поменять
//     местами строки и столбцы с одинаковыми номерами
//

#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {

  int array[5][9];

  int seed = system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  uniform_int_distribution<int> distribution(0, 9);

  for (auto & i : array) {
    for (int & j : i) {
      j = distribution(generator);
    }
  }

  cout << setw(3);
  // Вывести сгенерированный массив
  for (auto & i : array) {
    for (int j : i) {
      cout << j << setw(3);
    }
    cout << endl;
  }
  cout << endl;

  // Создание нового массива
  int array_changed[5][9];

  // Запись строки одного в столбец другого
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      array_changed[i][j] = (j < 5) ? array[j][i] : array[i][j];
    }
  }

  // Вывод нового массива
  for (auto & i : array_changed) {
    for (int j : i) {
      cout << j << setw(3);
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
