#include <stdio.h>
#include <stdlib.h>

void pfile(FILE* file)
{
    char c = '\0';
    while ((c = fgetc(file)) != EOF)
        printf("%c", c);
    printf("\n");
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("[ERROR] No file provided");
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;
    
    printf("Enter a string to add: ");
    getline(&line, &len, stdin);
    printf("\n");

    FILE* file;

    if((file = fopen(argv[1], "r")) == NULL)
    {
        printf("[ERROR] Unable to read file at path: %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("File before changes:\n");
    pfile(file);

    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_copy = (char*)malloc(sizeof(char) * size);
    for(int i = 0;i < size; i++)
        file_copy[i] = fgetc(file);
    fclose(file);

    if((file = fopen(argv[1], "w")) == NULL)
    {
        printf("[ERROR] Unable to write to file at path: %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Potential expliot
    /*
        fprintf(file, line);
        fprintf(file, file_copy);
    */

    for(int i = 0; line[i] != '\0'; i++) // i < len doesn't work. Some how var len gets value 120.
        fprintf(file, "%c", line[i]);
    for(int i = 0; i < size; i++)
        fprintf(file, "%c", file_copy[i]);
    fclose(file);

    if((file = fopen(argv[1], "r")) == NULL)
    {
        printf("[ERROR] Unable to read file at path: %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("File after changes:\n");
    pfile(file);

    fclose(file);
    free(file_copy);
    free(line);

    return 0;
}
