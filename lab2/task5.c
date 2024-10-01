#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* PRODUCT_FORMAT_IN = "%20[^;];%d\n";
const char* PRODUCT_FORMAT_OUT = "%s;%d\n";

typedef struct {
    char name[21];
    int price;
} Product;

int num_lines(FILE* file) {
    char c = '\0';
    int lines = 0;

    while ((c = fgetc(file)) != EOF)
        if (c == '\n')
            lines++;
    fseek(file, 0, SEEK_SET);

    return lines;    
}

int compareByPrice(const void* a, const void* b) {
    Product *p1 = (Product*)a;
    Product *p2 = (Product*)b;

    return p1->price - p2->price;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("[ERROR] No file provided\n");
        exit(EXIT_FAILURE);
    }

    FILE* file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("[ERROR] Unable to read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int records = num_lines(file);

    Product* products = (Product*)malloc(sizeof(Product)*records);

    int read = 0;
    int i = 0;
    do {
        read = fscanf(file, PRODUCT_FORMAT_IN, products[i].name, &products[i].price);

        if (read == 2)
            i++;
        if (read != 2 && !feof(file)) {
            printf("Incorrect file format at line %d\n", i+1);
            exit(EXIT_FAILURE);
        }
        if (ferror(file)) {
            printf("Error reading file");
            exit(EXIT_FAILURE);
        }
    } while (!feof(file));
    
    qsort(products, records, sizeof(Product), compareByPrice);

    fclose(file);

    if ((file = fopen(argv[2], "w")) == NULL) {
        printf("[ERROR] Unable to wrtie to file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < records; i++)
        fprintf(file, PRODUCT_FORMAT_OUT, products[i].name, products[i].price);

    fclose(file);
    free(products);

    return 0;
}