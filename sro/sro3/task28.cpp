//
// Created by ybkuanysh on 2025/02/17.
//
#include <iostream>

using namespace std;

int main() {
  int arr[] = {1, 2, 3, 0, 0, 0, 0, 0, 9, 10, 0, 80, 5};
  int maxId = 0;

  for (int i = 0; i < size(arr); i++) {
    if (arr[i] > arr[maxId]) maxId = i;
  }

  int startId = 0, count = 0;

  for (int i = 0; i < size(arr); i++) {
    if(arr[i] == 0 && arr[i+1] == 0) {
      startId = i;
      while (arr[i + count] == 0) count++;
      break;
    }
  }
  cout << count << endl << startId<< endl;

  int newarr[size(arr) - count + 1];
  int local_counter = 0;
  for (int i = 0; i < size(arr); i++) {
    if (i == startId) {
      newarr[local_counter] = arr[maxId];
      local_counter++;
      while (startId + count > i) {
        cout << "debug: " << i << " arr[i]: " << arr[i] << endl;
        i++;
      }
    }
    newarr[local_counter] = arr[i];
    local_counter++;
  }

  for (int num : newarr) {
    cout << num << " ";
  }
  return 0;
}