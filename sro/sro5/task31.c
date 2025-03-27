#include <stdio.h>
#include <string.h>

int main() {
    // char text_input[100];
    // scanf("%s", &text_input);
    char text[] = "1a0 2d0d s2d0 g20e d3some_word_inside2d";
    const int MAX_VALUE = 100, MIN_VALUE = 10;

    int counter = 0;
    char last_int[100];
    int scanned_num = 0, result = 0;
    char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i < strlen(text); i++) {
        counter = 0;

        while (text[i] != ' ' && text[i] != '\0') {
            for (int j = 0; j < 10; j++) {
                if (text[i] == nums[j]) {
                    last_int[counter] = text[i];
                    counter++;
                }
            }
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