//
// Created by ybkuanysh on 2025/03/07.
//
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int ar[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                ar[i][j] = 0;
            }
            for (int num = 0; num < i; num++) {
                ar[i][j] = rand() % 3;
                ar[j][i] = 2 - ar[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (ar[j][i] == 2) counter++;
        }
        if (counter >= 3) {
            printf("Teams %d ", i);
            printf("count of wins %d\n", counter);
        }
        counter = 0;
    }

    return 0;
}
