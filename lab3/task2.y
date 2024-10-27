%{
#include <stdio.h>

int yylex();
void yyerror(char* str);
int main(int argc, char** argv);
%}

%token NUMBER
%token ADD SUB
%token OP EP
%token EOL

%%
calclsist: %empty   
    | calclsist exp EOL { printf(" = %d\n", $2); }
    ;

exp: term
    | exp ADD term    { $$ = $1 + $3; }
    | exp SUB term    { $$ = $1 - $3; }
    ;

term: NUMBER
    | OP exp EP         { $$ = $2; }
    ;
%%

void yyerror(char* str) {
    fprintf(stderr, "[ERROR]: %s\n", str);
}

int main(int argc, char** argv) {
    yyparse();
    return 0;
}
