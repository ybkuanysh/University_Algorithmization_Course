//
// Created by ybkuanysh on 2025/04/13.
//

/*
 *  Текст задачи: Входной файл содержит информацию о студентах некоторого
 *                факультета (struct). Требуется в выходной файл записать
 *                сведения о тех студентах, которые  среди самых  молодых
 *                имеют максимальный средний бал в каждой группе.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GROUPS_Q 100
#define GROUP_NAME_LEN 20

// Статусы возвращаемые функциями
#define STATUS_SUCCESS 0
#define STATUS_FAILURE 1

struct Rec1 {
    long nomer; // номер записи в файле
    char name[20]; // фамилия
    int year; // год рождения
    char group[20]; // группа
    float sred; // средний балл
};

int records_counter = 0;


// Создание файла данных, элементами которого являются
// записи со структурой указанной в индивидуальном варианте
int CreateFileIn(char *fileName);

// Добавление записей в конец входного файла
int AddFileIn(char *fileName);

// Просмотр записей во входном файле последовательно
// от первой до последней
int ReadFileIn(char *fileName);

// Обработка данных из входного файла по заданию
// индивидуального варианта и вывод результатов в
// выходной файл
int CreateFileOut(char *fileName1, char *fileName2);

// Просмотр записей в выходном файле последовательно
int ReadFileOut(char *fileName);

int main(void) {
    char *fileName = "file_sro7.data";
    char *fileNameEdited = "file_sro7_edited.data";

    if (CreateFileIn(fileName) == STATUS_FAILURE) {
        printf("ERROR while creating new file %s\n", fileName);
    }

    if (AddFileIn(fileName) == STATUS_FAILURE) {
        printf("ERROR while adding new data to the file %s\n", fileName);
    }

    if (ReadFileIn(fileName) == STATUS_FAILURE) {
        printf("ERROR while reading from file %s\n", fileName);
    }
    printf("\n");

    if (CreateFileOut(fileName, fileNameEdited) == STATUS_FAILURE) {
        printf("ERROR while creating new edited file\n");
    }

    if (ReadFileOut(fileNameEdited) == STATUS_FAILURE) {
        printf("ERROR while reading from file %s\n", fileNameEdited);
    }

    return 0;
}

int CreateFileIn(char *fileName) {
    const struct Rec1 students[] = {
        {++records_counter, "Ivanov", 2003, "BT-21", 4.2f},
        {++records_counter, "Sergeev", 2003, "BT-21", 3.8f},
        {++records_counter, "Akhmetov", 2003, "BT-21", 4.5f},
        {++records_counter, "Nurgaliev", 2004, "BT-21", 4.0f},
        {++records_counter, "Tursynov", 2004, "BT-21", 3.6f},
        {++records_counter, "Petrov", 2005, "BT-21", 4.1f},
        {++records_counter, "Smagulov", 2005, "BT-21", 3.9f},
        {++records_counter, "Kuznetsov", 2004, "IS-20", 4.3f},
        {++records_counter, "Zhumabayev", 2005, "IS-20", 4.4f},
        {++records_counter, "Vasiliev", 2004, "IS-20", 3.7f},
    };

    const int n = sizeof(students) / sizeof(students[0]);

    FILE *fp = fopen(fileName, "wb");

    if (!fp) {
        printf("Error opening file %s\n", fileName);
        return STATUS_FAILURE;
    }

    // fwrite(&n, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Rec1), n, fp);

    fclose(fp);

    printf("File %s created successfully with %d records\n", fileName, n);

    return STATUS_SUCCESS;
}

int AddFileIn(char *fileName) {
    const struct Rec1 students[] = {
        {++records_counter, "Sidorov", 2005, "IS-21", 4.7f},
        {++records_counter, "Erzhanov", 2003, "PM-19", 4.6f}
    };

    const int n = sizeof(students) / sizeof(students[0]);

    FILE *fp = fopen(fileName, "ab");

    if (!fp) {
        printf("Error opening file %s\n", fileName);
        return STATUS_FAILURE;
    }

    // fwrite(&n, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Rec1), n, fp);

    fclose(fp);

    printf("Successfully added %d records to the file %s\n", n, fileName);

    return STATUS_SUCCESS;
}

int ReadFileIn(char *fileName) {
    FILE *fp = fopen(fileName, "rb");

    if (!fp) {
        printf("Error opening file %s\n", fileName);
        return STATUS_FAILURE;
    }

    // Чтение записей из файла без переменной количества записей
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    size_t recordCount = fileSize / sizeof(struct Rec1);

    struct Rec1 *students = malloc(sizeof(struct Rec1) * recordCount);

    if (!students) {
        printf("Error allocating memory for students\n");
        return STATUS_FAILURE;
    }

    size_t readCount = fread(students, sizeof(struct Rec1), recordCount, fp);
    fclose(fp);

    if (readCount != recordCount) {
        printf("Error reading data from file: expected %zu, received %zu\n",
               recordCount, readCount);
        free(students);
        return STATUS_FAILURE;
    }

    printf("| N   | Family name     | Year | Group | GPA  |\n");
    printf("|---------------------------------------------|\n");

    for (int i = 0; i < recordCount; i++) {
        printf("| %-3ld | %-15s | %4d | %5s | %4.2f |\n",
               students[i].nomer,
               students[i].name,
               students[i].year,
               students[i].group,
               students[i].sred
        );
    }

    free(students);

    return STATUS_SUCCESS;
}

int CreateFileOut(char *fileName1, char *fileName2) {
    FILE *fp = fopen(fileName1, "rb");

    if (!fp) {
        printf("Error opening file %s\n", fileName1);
        return STATUS_FAILURE;
    }

    // Скопировано из ReadFileIn()
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    size_t recordCount = fileSize / sizeof(struct Rec1);

    struct Rec1 *students = malloc(sizeof(struct Rec1) * recordCount);

    if (!students) {
        printf("Error allocating memory for students\n");
        return STATUS_FAILURE;
    }

    size_t readCount = fread(students, sizeof(struct Rec1), recordCount, fp);
    fclose(fp);

    if (readCount != recordCount) {
        printf("Error reading data from file: expected %zu, received %zu\n",
               recordCount, readCount);
        free(students);
        return STATUS_FAILURE;
    }
    // Конец копирования

    // Узнаем сколько всего и каких групп есть в списке
    char unique_groups[MAX_GROUPS_Q][GROUP_NAME_LEN];
    int group_count = 0;

    for (int i = 0; i < recordCount; ++i) {
        int already_exists = 0;

        for (int j = 0; j < group_count; ++j) {
            if (strcmp(students[i].group, unique_groups[j]) == 0) {
                already_exists = 1;
                break;
            }
        }

        if (!already_exists) {
            strcpy(unique_groups[group_count], students[i].group);
            group_count++;
        }
    }

    FILE *fp2 = fopen(fileName2, "wb");

    for (int i = 0; i < group_count; i++) {
        // Узнаем год рождения самых молодых студентов для каждой группы
        int max_year = 0;
        for (int j = 0; j < records_counter; j++) {
            if (strcmp(students[j].group, unique_groups[i]) == 0) {
                if (students[j].year > max_year) {
                    max_year = students[j].year;
                }
            }
        }

        // Находим студентов с самым высоким GPA, среди самых молодых
        double max_gpa = 0.0;
        int student_id = 0;
        for (int j = 0; j < records_counter; j++) {
            if (strcmp(students[j].group, unique_groups[i]) == 0) {
                if (students[j].year == max_year && students[j].sred > max_gpa) {
                    max_gpa = students[j].sred;
                    student_id = j;
                }
            }
        }
        fwrite(&students[student_id], sizeof(struct Rec1), 1, fp2);
    }
    free(students);
    fclose(fp2);

    printf("File %s successfully created\n", fileName2);

    return STATUS_SUCCESS;
}

int ReadFileOut(char *fileName) {
    printf("Students with MAX GPA:\n");
    return ReadFileIn(fileName);
}
