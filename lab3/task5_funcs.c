#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "task5.h"
#include "task5.tab.h"

struct ast* newast(int nodetype, struct ast* l, struct ast* r) {
    struct ast* a = malloc(sizeof(struct ast));
    
    if(!a) {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

struct ast* newnum(double d) {
    struct numval* a = malloc(sizeof(struct numval));
    
    if(!a) {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = 'C';
    a->number = d;
    return (struct ast* )a;
}

double eval(struct ast* a) {
    double v;

    switch(a->nodetype) {
        case 'C': v = ((struct numval*)a)->number; break;

        case '+': v = eval(a->l) + eval(a->r); break;
        case '-': v = eval(a->l) - eval(a->r); break;
        case '*': v = eval(a->l) * eval(a->r); break;
        case '/': v = eval(a->l) / eval(a->r); break;
        case 'M': v = -eval(a->l); break;
        default: printf("[ERROR]: bad node %c\n", a->nodetype);
    }

    return v;
}

void treefree(struct ast *a) {
    switch(a->nodetype) {
        case '+':
        case '-':
        case '*':
        case '/':
            treefree(a->r);
        case 'M':
            treefree(a->l);
        case 'C':
            free(a);
            break;
        default: printf("[ERROR]: free bad node %c\n", a->nodetype);
    }
}

void yyerror(char *s, ...) {
    va_list ap;
    va_start(ap, s);
    
    fprintf(stderr, "[ERROR]: ");
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}

int main() {
    printf("> "); 
    return yyparse();
}