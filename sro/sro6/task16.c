//
// Created by ybkuanysh on 2025/04/03.
//
#include <stdio.h>

int isTriangle(int a, int b, int c);

int main() {
  int a, b, c;
  printf("Enter a, b, c: ");
  scanf("%d%d%d", &a, &b, &c);
  if (isTriangle(a, b, c)) {
    printf("Triangle is true\n");
  }
  else {
    printf("Triangle is false\n");
  }
}

int isTriangle(int a, int b, int c) {
  if (a + b <= c || a + c <= b || b + c <= a) {
    return 0;
  }
  return 1;
}
