//
// Created by ybkuanysh on 2025/04/11.
//
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *filename = "file.txt";
    char *filename_new = "new_file.txt";
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error occurred while opening file\n");
        return -1;
    }

    char buffer[256];
    int counter = 0;
    int max_num = 0;
    int current_num = 0;

    if (fp) {
        while ((fgets(buffer, 256, fp)) != NULL) {
            counter++;
            if (counter % 2 != 0) {
                current_num = abs(atoi(buffer));
                if (current_num > max_num) {
                    max_num = current_num;
                }
            }
            printf("%s", buffer);
        }
        fclose(fp);
    }

    printf("\nMax: %d", max_num);

    FILE *fp_new = fopen(filename_new, "w");
    if (fp_new) {
        fprintf(fp_new, "%d", max_num); // сохраняем число как строку
        fclose(fp_new);
    }

    return 0;
}
