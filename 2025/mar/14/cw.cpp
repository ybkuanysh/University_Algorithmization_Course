//
// Created by ybkuanysh on 2025/03/14.
//
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {

  size_t N = 10;

  int array_1[N];
  int array_2[N/2][N/2];

  int seed = system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  uniform_int_distribution distribution(-100, 100);

  cout << "Одномерный массив заполненный случайными числами: " << endl;
  for (int &i: array_1) {
    i = distribution(generator);
    cout << setw(5) << i;
  }
  cout << endl;


  for (int i = 0; i < N/2; i++) {
    for (int j = 0; j < N/2; j++) {
      if (i == j || i == N/2 - j - 1) {
        array_2[i][j] = i != N/2-j-1 ? array_1[i] : array_1[N-i-1];
      }
      else if (i > j) array_2[i][j] = i>N/2-1-j ? 1 : 0;
      else array_2[i][j] = i<N/2-1-j ? 1 : 0;
    }
  }

  cout << "Двумерный массив: " << endl;
  for (int i = 0; i < N/2; i++) {
    for (int j = 0; j < N/2; j++) {
      cout << setw(5) << array_2[i][j];
    }
    cout << endl;
  }

  return 0;
}