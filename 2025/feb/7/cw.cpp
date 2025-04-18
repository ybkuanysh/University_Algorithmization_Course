//
// Created by ybkuanysh on 2025/02/07.
//
/*
    1. Пузырьковая
    2. Пузырьковая с флагом
    3. Пузырьковая улучшенная
    4. Пузырьковая улучшенная с флагом
    5. Любая пузырьковая по убыванию
    6. Вставками
    7. Выбора max по возрастанию
    8. Выбора min по возрастанию
    9. Выбора max по убыванию
    10. Выбора min по убыванию
 */
#include <iostream>
#include <random>
#include <chrono>

#define PRESENTATION_MODE
// #define FLAG_MODE

using namespace std;
using namespace chrono;

int main() {
#ifdef PRESENTATION_MODE
    int type_of_algorithm = 1;
    cout <<
            "1. Пузырьковая\n2. Пузырьковая с флагом\n3. Пузырьковая улучшенная\n4. Пузырьковая улучшенная с флагом\n5. Любая пузырьковая по убыванию\n6. Вставками\n7. Выбора max по возрастанию\n8. Выбора min по возрастанию\n9. Выбора max по убыванию\n10. Выбора min по убыванию\n";
    cout << "Выберите алгоритм сортировки: ";
    cin >> type_of_algorithm;
#endif

    // Counter of iterations
    int count_iterations = 0;
    // For sort with flag
    bool notSorted;

#ifndef FLAG_MODE
    // array generation
    int arr[30];
    int seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution distribution(-100, 100);
    for (int &i: arr) {
        i = distribution(generator);
    }
#endif
#ifdef FLAG_MODE
    int arr[] = {15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
#endif

    // Place to debug algorithm
#ifndef PRESENTATION_MODE
    // CODE HERE -----------------------------------

    // CODE ENDS HERE--------------------------------

    for (int i = 0; i < size(arr); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Iterations of sorting: " << count_iterations << endl;
#endif

#ifdef PRESENTATION_MODE
    switch (type_of_algorithm) {
        case 1:
            for (int i = 0; i < size(arr); i++) {
                for (int j = 0; j < size(arr) - 1; j++) {
                    count_iterations++;
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < size(arr); i++) {
                notSorted = false;
                for (int j = 0; j < size(arr) - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        notSorted = true;
                    }
                    count_iterations++;
                }
                if (notSorted == false) break;
            }
            break;
        case 3:
            for (int i = 0; i < size(arr); i++) {
                for (int j = 0; j < size(arr) - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                    count_iterations++;
                }
            }
            break;
        case 4:
            for (int i = 0; i < size(arr); i++) {
                notSorted = false;
                for (int j = 0; j < size(arr) - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        notSorted = true;
                    }
                    count_iterations++;
                }
                if (notSorted == false) break;
            }
            break;
        case 5:
            for (int i = 0; i < size(arr); i++) {
                notSorted = false;
                for (int j = 0; j < size(arr) - i - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        notSorted = true;
                    }
                    count_iterations++;
                }
                if (notSorted == false) break;
            }
            break;
        case 6:
            for (int i = 1; i < size(arr); i++) {
                for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
                    count_iterations++;
                    swap(arr[j], arr[j - 1]);
                }
            }
            break;
        case 7: // Выбора max по возрастанию
            for (int i = 0; i < size(arr); i++) {
                int maxId = 0;
                for (int j = 0; j < size(arr) - i; j++) {
                    count_iterations++;
                    if (arr[j] > arr[maxId]) maxId = j;
                }
                swap(arr[size(arr) - i - 1], arr[maxId]);
            }
            break;
        case 8:
            for (int i = 0; i < size(arr) - 1; i++) {
                int minId = i;
                for (int j = i + 1; j < size(arr); j++) {
                    if (arr[j] < arr[minId]) minId = j;
                }
                swap(arr[i], arr[minId]);
            }
            break;
        case 9:
            for (int i = 0; i < size(arr) - 1; i++) {
                int maxId = i;
                for (int j = i + 1; j < size(arr); j++) {
                    if (arr[j] > arr[maxId]) maxId = j;
                }
                swap(arr[i], arr[maxId]);
            }
            break;
        case 10:
            for (int i = 0; i < size(arr); i++) {
                int minId = 0;
                for (int j = 0; j < size(arr) - i; j++) {
                    count_iterations++;
                    if (arr[j] < arr[minId]) minId = j;
                }
                swap(arr[size(arr) - i - 1], arr[minId]);
            }
            break;
        default:
            cout << "Выбранный алгоритм не существует";
    }

    // Show result of sorting in commandline
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl << "Итераций сортировки: " << count_iterations << endl;

#endif
    return 0;
}
