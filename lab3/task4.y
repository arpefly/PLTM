%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char* str);
int main(int argc, char** argv);
%}

%union {
    double d;
}

%token <d> NUMBER
%left '+' '-'
%left '*' '/'
%token EOL

%%
calclsist: %empty   
    | calclsist exp EOL { printf("\n"); }
    ;

exp: factor
    | exp '+' factor    { printf("+ "); }
    | exp '-' factor    { printf("- "); }
    ;

factor: term
    | factor '*' term   { printf("*"); }
    | factor '/' term   { printf("/"); }
    ;

term: NUMBER            { printf("%.2f ", $1); }
    | '(' exp ')'       { }
    ;
%%

void yyerror(char* str) {
    fprintf(stderr, "[ERROR]: %s\n", str);
}

int main(int argc, char** argv) {
    yyparse();
    return 0;
}
