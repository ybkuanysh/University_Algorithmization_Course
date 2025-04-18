//
// Created by ybkuanysh on 2025/04/18.
//
#include <stdio.h>
#include <stdlib.h>

struct track {
    char singer[100];
    char genre[40];
    char album[100];
    long copies;
};

int save(char *filename, struct track *f, int n);
int load(char *filename, long min_copies_count);

int main(void) {
    char *filename = "tracks.data";

    struct track tracks[10] = {
        {"Hikaru Utada", "J-Pop", "First Love", 10000000},
        {"YOASOBI", "J-Pop", "The Book", 5000000},
        {"LiSA", "Anime Rock", "LEO-NiNE", 7000000},
        {"Aimer", "J-Pop", "UnChild", 3000000},
        {"Official HIGE DANDism", "J-Rock", "Traveler", 6000},
        {"Taylor Swift", "Pop", "1989", 1200},
        {"Michael Jackson", "Pop", "Thriller", 6000},
        {"Beyonce", "R&B", "Lemonade", 6000},
        {"Billie Eilish", "Alternative", "WHEN WE ALL FALL...", 7000000},
        {"Eminem", "Rap", "The Marshall Mathers LP", 11000000}
    };

    int n = sizeof(tracks) / sizeof(tracks[0]);


    save(filename, tracks, n);

    // Вывод с чтением из файла
    int min_copies_count = 10000;
    load(filename, min_copies_count);

    return 0;
}

int save(char *filename, struct track *f, int n) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error occurred while opening file\n");
        return -1;
    }

    fwrite(&n, sizeof(int), 1, fp);

    fwrite(f, sizeof(struct track), n, fp);

    fclose(fp);
    return 0;
}

int load(char *filename, long min_copies_count) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error occurred while opening file\n");
        return -1;
    }

    int n;
    fread(&n, sizeof(int), 1, fp);

    struct track *ptr = malloc(n * sizeof(struct track));
    if (!ptr) {
        printf("Memory allocation error\n");
        fclose(fp);
        return -1;
    }

    fread(ptr, sizeof(struct track), n, fp);

    printf("| %-2s | %-25s | %-25s | %-15s | %-8s |\n",
           "N","Album", "Singer", "Genre", "Copies");
    printf("-------------------------------------------------------------------------------------------\n");

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (ptr[i].copies >= min_copies_count) {
            printf("| %-2d | %-25s | %-25s | %-15s | %-8ld |\n",
                   ++counter, ptr[i].album, ptr[i].singer, ptr[i].genre, ptr[i].copies);
        }
    }

    free(ptr);
    fclose(fp);
    return 0;
}
