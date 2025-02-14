//
// Created by ybkuanysh on 2025/01/31.
//
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {

  int pupils[22];
  int r = 175;

  int seed = system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  uniform_int_distribution<int> distribution(160, 190);

  int counter = 0;
  for (int i = 0; i < size(pupils); i++) {
    pupils[i] = distribution(generator);
    if (pupils[i] < r) counter++;
  }
  cout << counter << endl;
}