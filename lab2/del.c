#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *input;
char token;

void nextToken() {
    token = *input++;
}

void error() {
    printf("Error: invalid expression\n");
    exit(1);
}

void E();  // Forward declaration
void EPrime();
void T();
void TPrime();
void F();

// Function to handle E -> T E'
void E() {
    T();
    EPrime();
}

// Function to handle E' -> + T E' { print('+') } | - T E' { print('-') } | ε
void EPrime() {
    if (token == '+') {
        nextToken();
        T();
        printf("+ ");
        EPrime();
    } else if (token == '-') {
        nextToken();
        T();
        printf("- ");
        EPrime();
    }
}

// Function to handle T -> F T'
void T() {
    F();
    TPrime();
}

// Function to handle T' -> * F T' { print('*') } | / F T' { print('/') } | ε
void TPrime() {
    if (token == '*') {
        nextToken();
        F();
        printf("* ");
        TPrime();
    } else if (token == '/') {
        nextToken();
        F();
        printf("/ ");
        TPrime();
    }
}

// Function to handle F -> ( E ) | digit { print(digit) }
void F() {
    if (token == '(') {
        nextToken();
        E();
        if (token == ')') {
            nextToken();
        } else {
            error();
        }
    } else if (isdigit(token)) {
        printf("%c ", token);
        nextToken();
    } else {
        error();
    }
}

// Main function to start parsing
void parse(char *expr) {
    input = expr;
    nextToken();
    E();
    if (token != '\0') {
        error();
    }
    printf("\n");
}

int main() {
    // Testing with various input expressions
    char expr1[] = "3+4*2/(1-5)";
    char expr2[] = "(1+2)*(3+4)";
    char expr3[] = "5*(6+2)-8/4";

    printf("Expression 1: %s\nPostfix: ", expr1);
    parse(expr1);  // Expected output: 3 4 2 * 1 5 - / +

    printf("Expression 2: %s\nPostfix: ", expr2);
    parse(expr2);  // Expected output: 1 2 + 3 4 + *

    printf("Expression 3: %s\nPostfix: ", expr3);
    parse(expr3);  // Expected output: 5 6 2 + * 8 4 / -

    return 0;
}