#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.c"

int main(int argc, char* argv[]) {
    stack* stek = init(0);
    
    FILE* file;
    char* line = NULL;
    size_t len = 0;

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("[ERROR] Unable to read file at path: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    getline(&line, &len, file);
    fclose(file);

    printf("%s\n", line);

    char c = '\0';
    double right, left = 0;
    for (int i = 0; i < line[i] != '\0'; i++)
    {
        c = line[i];
        if (isdigit(line[i])) {
            push(&stek, (double)c-48);
        }
        else {
            right = pop(&stek);
            left = pop(&stek);
        
            switch (c)
            {
                case '+':
                    push(&stek, left+right);
                    break;
                case '-':
                    push(&stek, left-right);
                    break;
                case '*':
                    push(&stek, left*right);
                    break;
                case '/':
                    push(&stek, left/right);
                    break;
            }
        }
    }

    printf("%lf\n", pop(&stek));

    dispose(&stek);
    return 0;   
}
