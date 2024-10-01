#include <stdio.h>
#include <ctype.h>
#include "stack.c"

T calc(char* strin) {
    stack* stck = NULL  ;
    
    FILE* file = NULL;
    char* line = NULL;
    size_t len = 0;

    if ((file = fopen(strin, "r")) == NULL) {
        printf("[ERROR] Unable to read file at path: %s\n", strin);
        return 1;
    }

    getline(&line, &len, file);
    fclose(file);
    
    printf("%s\n", line);

    char c = '\0';
    double right, left = 0;
    for (int i = 0; i < line[i] != '\0'; i++)
    {
        c = line[i];
        if (isdigit(c)) {
            push(&stck, (double)c-48);
        }
        else {
            right = pop(&stck);
            left = pop(&stck);
        
            switch (c)
            {
                case '+':
                    push(&stck, left+right);
                    break;
                case '-':
                    push(&stck, left-right);
                    break;
                case '*':
                    push(&stck, left*right);
                    break;
                case '/':
                    push(&stck, left/right);
                    break;
                default:
                    return 1;
            }
        }
    }

    printf("%lf\n", pop(&stck));

    dispose(&stck);
    return 0;
}

int main(int argc, char* argv[]) {
    return calc(argv[1]);
}
