#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main() {
    const int N = 6;

    int selection = 1;
    cout << "1. С края по часовой\n2. С края против часовой\n3. С центра против часовой\n4. С центра по часовой\n5. С центра по часовой\n6. С края против часовой\n7. Дополнительная задача\n";
    cout << "Выберите вид заполнения массива: ";
    cin >> selection;

    int m[N][N] = {0};

    switch (selection) {
        case 1: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int x = min(min(i, j), min(N - 1 - i, N - 1 - j));
                    m[i][j] = N * N + 1 - (i > j
                                               ? (N - 2 * x - 2) * (N - 2 * x - 2) + (i - x) + (j - x)
                                               : (N - 2 * x) * (N - 2 * x) - (i - x) - (j - x)
                              );
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int x = min(min(i, j), min(N - 1 - i, N - 1 - j));
                    m[N-i-1][N-j-1] = N * N + 1 - (i > j
                                               ? (N - 2 * x - 2) * (N - 2 * x - 2) + (i - x) + (j - x)
                                               : (N - 2 * x) * (N - 2 * x) - (i - x) - (j - x)
                              );
                }
            }
            break;
        }
        case 3: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int x = min(min(i, j), min(N - 1 - i, N - 1 - j));
                    m[j][i] = (i < j
                                   ? (N - 2 * x - 2) * (N - 2 * x - 2) + (i - x) + (j - x)
                                   : (N - 2 * x) * (N - 2 * x) - (i - x) - (j - x)
                    );
                }
            }
            break;
        }
        case 4: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int x = min(min(i, j), min(N - 1 - i, N - 1 - j));
                    m[N - 1 - i][N - j - 1] = (i > j
                                   ? (N - 2 * x - 2) * (N - 2 * x - 2) + (i - x) + (j - x)
                                   : (N - 2 * x) * (N - 2 * x) - (i - x) - (j - x)
                    );
                }
            }
            break;
        }
        case 5: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int x = min(min(i, j), min(N - 1 - i, N - 1 - j));
                    m[i][N - 1 - j] = (i > j
                                   ? (N - 2 * x - 2) * (N - 2 * x - 2) + (i - x) + (j - x)
                                   : (N - 2 * x) * (N - 2 * x) - (i - x) - (j - x)
                    );
                }
            }
            break;
        }
        case 6: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int x = min(min(i, j), min(N - 1 - i, N - 1 - j));
                    m[i][N - 1 - j] = N*N+1 - (i > j
                                   ? (N - 2 * x - 2) * (N - 2 * x - 2) + (i - x) + (j - x)
                                   : (N - 2 * x) * (N - 2 * x) - (i - x) - (j - x)
                    );
                }
            }
            break;
        }
        case 7: {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    m[i][j] = i == j || N - 1 - i == j ? 1 : 0;
                }
            }
            break;
        }
    }


    for (auto & i : m) {
        for (int j : i) {
            cout << setw(5) << j;
        }
        cout << endl;
    }

    return 0;
}
