#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.c"

int parse(char* strin, char* strout) {
    int prior(char c) {
        switch (c) {
            case '*': case '/': return 3;
            case '+': case '-': return 2;
            case '(': return 1;
            default: return 0;
        }
    }

    FILE* file = NULL;

    if ((file = fopen(strin, "r")) == NULL) {
        printf("[ERROR] Unable to read file at path: %s\n", strin);
        return 1;
    }

    char* line = NULL;
    size_t len = 0;

    getline(&line, &len, file);
    fclose(file);

    if ((file = fopen(strout, "w")) == NULL) {
        printf("[ERROR] Unable to write to file at path: %s\n", strout);
        return 1;
    }

    stack* stck = NULL;

    for (int i = 0; i < line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            fputc(line[i], file);
        }
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') {
            if (empty(stck) || (prior(peek(stck)) < prior(line[i]))) {
                push(&stck, line[i]);
            }
            else if (prior(peek(stck)) >= prior(line[i])) {
                while (prior(peek(stck)) >= prior(line[i]))
                    fputc(pop(&stck), file);
                if (empty(stck) || (prior(peek(stck)) < prior(line[i])))
                    push(&stck, line[i]);
            }
        }
        else if (line[i] == '(') {
            push(&stck, '(');
        }
        else if (line[i] == ')') {
            while (prior(peek(stck)) != 1)
                fputc(pop(&stck), file);
            pop(&stck); // destroy unnecessary '(' in stack
        }
    }

    while (!empty(stck))
        fputc(pop(&stck), file);

    fclose(file);
    dispose(&stck);
}

int main(int argc, char* argv[]) {
    return parse(argv[1], argv[2]);
}
