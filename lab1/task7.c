#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* file;
    int flag = 0;
    char c = '\0';

    if ((file = fopen(argv[1], "a+")) != NULL)
    {
        printf("File before changes:\n");
        while ((c = fgetc(file)) != EOF)
            printf("%c", c);
        printf("\n");
        
        fprintf(file, "new test\n");

        printf("File after changes:\n");
        fseek(file, 0, SEEK_SET);
        while ((c = fgetc(file)) != EOF)
            printf("%c", c);

        fclose(file);
    }
    else
    {
        printf("[ERROR] Unable to append to file at path: %s\n", argv[1]);
        flag++;
    }

    return flag;
}
