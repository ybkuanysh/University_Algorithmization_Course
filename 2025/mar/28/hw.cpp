//
// Created by ybkuanysh on 2025/04/04.
//
#include <iostream>

using namespace std;

void hanoi_towers(int count, int from, int to, int buf);

int main() {

  int count, from, to, buf;
  cout << "Введите количество дисков: ";
  cin >> count;
  cout << "Введите номер начального колышка: ";
  cin >> from;
  cout << "Введите номер конечного колышка: ";
  cin >> to;
  cout << "Введите номер буферного колышка: ";
  cin >> buf;
  hanoi_towers(count, from, to, buf);
}

void hanoi_towers(int count, int from, int to, int buf) {
  if (count != 0) {
    hanoi_towers(count - 1, from, buf, to);

    cout << from << " --> " << to << endl;

    hanoi_towers(count - 1, buf, to, from);
  }
}
