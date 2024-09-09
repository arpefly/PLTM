#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* file;
    int i = 1;
    char c = '\0'; // temp char to read file
    
    if (argc == 1)
    {
        // printf("[ERROR] No files provided\n");
        while((c = fgetc(stdin)) != EOF)
            putc(c, stdout);
        return 0;
    }

    while (i < argc)
    {
        if ((file = fopen(argv[i++], "r")) == NULL)
            printf("[ERROR] Unable to read file at path: %s\n", argv[i - 1]);
        else
        {
            while ((c = fgetc(file)) != EOF)
                printf("%c", c);
            printf("\n");

            fclose(file);
        }
    }

    return 0;
}
