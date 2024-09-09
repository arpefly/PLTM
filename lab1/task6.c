#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file1;
    FILE* file2;
    char* line = NULL;
    size_t len = 0;
    int i = 0;

    file1 = fopen("task6in.txt", "r");
    
    if (file1 == NULL)
    {
        printf("[ERROR] Unable to read file at path: task6in.txt");
        exit(EXIT_FAILURE);
    }

    file2 = fopen("task6out.txt", "w");
    
    if (file2 == NULL)
    {
        printf("[ERROR] Unable to write to file at path: task6out.txt");
        exit(EXIT_FAILURE);
    }
    
    while ((getline(&line, &len, file1)) != EOF && i < 3)
    {
        fprintf(file2, line);
        i++;
    }

    fclose(file1);
    fclose(file2);
    free(line);
    
    return 0;
}
