#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "1 12 30 432 23 122 67 20 1234";
    const int MAX_VALUE = 100, MIN_VALUE = 10;

    int counter = 0;
    char last_int[100];
    int scanned_num = 0, result = 0;

    for (int i = 0; i < strlen(text); i++) {
        counter = 0;

        while (text[i] != ' ' && text[i] != '\0') {
            last_int[counter] = text[i];
            counter++;
            i++;
        }

        last_int[counter] = '\0';

        if (sscanf(last_int, "%d", &scanned_num) == 1) {
            if (scanned_num <= MAX_VALUE && scanned_num >= MIN_VALUE) {
                result += scanned_num;
            }
        }

        scanned_num = 0;
        last_int[0] = '\0';
    }

    printf("Result: %d\n", result);
    return 0;
}
