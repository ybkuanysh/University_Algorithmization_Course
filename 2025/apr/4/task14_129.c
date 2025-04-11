#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct film {
    char film_name[40];
    char director_name[40];
    int year;
    char country[40];
    double ticket_price;
    double income;
    double profit;
};

int save(char *filename, struct film *f, int n);

int load(char *filename, char *filename2, const char director_name[40]);

int main(void) {
    char *filename = "film.txt";
    char *filename2 = "film2.txt";

    struct film films[] = {
        {"Potop", "J. Hoffman", 1974, "Poland", 5.00, 12000000.00, 8000000.00},
        {"Ogniem i Mieczem", "J. Hoffman", 1999, "Poland", 6.50, 17000000.00, 10000000.00},
        {"Wolodyjowski", "J. Hoffman", 1969, "Poland", 4.00, 9000000.00, 6000000.00},
        {"Ogniem i Mieczem", "Someone", 1999, "Poland", 6.50, 17000000.00, 10000000.00}
    };

    int n = sizeof(films) / sizeof(films[0]);

    printf("%-20s %-15s %5s %-10s %13s %13s %13s\n",
           "Film", "Director", "Year", "Country", "Ticket Price", "Income", "Profit");
    printf("---------------------------------------------------------------------------------------------\n");

    save(filename, films, n);
    load(filename, filename2, "J. Hoffman");

    return 0;
}

int save(char *filename, struct film *f, int n) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error occurred while opening file\n");
        return -1;
    }

    fwrite(&n, sizeof(int), 1, fp);

    fwrite(f, sizeof(struct film), n, fp);

    fclose(fp);
    return 0;
}

int load(char *filename, char *filename2, const char director_name[40]) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error occurred while opening file\n");
        return -1;
    }

    int n;
    fread(&n, sizeof(int), 1, fp);

    struct film *ptr = malloc(n * sizeof(struct film));
    if (!ptr) {
        printf("Memory allocation error\n");
        fclose(fp);
        return -1;
    }

    fread(ptr, sizeof(struct film), n, fp);

    FILE *fp2 = fopen(filename2, "wb");

    for (int i = 0; i < n; i++) {
        if (strcmp(ptr[i].director_name, director_name) == 0) {
            printf("%-20s %-15s %5d %-10s %13.2f %13.2f %13.2f\n",
                   ptr[i].film_name, ptr[i].director_name, ptr[i].year,
                   ptr[i].country, ptr[i].ticket_price, ptr[i].income, ptr[i].profit);

            fwrite(&ptr[i], sizeof(struct film), 1, fp2);
        }
    }

    free(ptr);
    fclose(fp2);
    fclose(fp);
    return 0;
}
