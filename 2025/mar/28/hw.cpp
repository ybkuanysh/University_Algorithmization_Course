//
// Created by ybkuanysh on 2025/04/04.
//
#include <iostream>

using namespace std;

void hanoi_towers(int count, int from, int to, int buf);

int main() {

  int count, from, to, buf;
  cout << "������ ������⢮ ��᪮�: ";
  cin >> count;
  cout << "������ ����� ��砫쭮�� ����誠: ";
  cin >> from;
  cout << "������ ����� ����筮�� ����誠: ";
  cin >> to;
  cout << "������ ����� ���୮�� ����誠: ";
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
