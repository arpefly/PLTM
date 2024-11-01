%{
#include <stdio.h>
#include <stdlib.h>
#include "task5.h"

int yylex();
%}

%union {
  struct ast* a;
  double d;
}

%token <d> NUMBER
%token EOL
%type <a> exp factor term
./
%%
calclist: %empty
    | calclist exp EOL {
        printf("= %4.4f\n", eval($2));
        treefree($2);
        printf("> ");
    }
    | calclist EOL      { printf("> "); }
    ;

exp: factor
    | exp '+' factor    { $$ = newast('+', $1,$3); }
    | exp '-' factor    { $$ = newast('-', $1,$3); }
    ;

factor: term
    | factor '*' term   { $$ = newast('*', $1,$3); }
    | factor '/' term   { $$ = newast('/', $1,$3); }
    ;

term: NUMBER            { $$ = newnum($1); }
    | '(' exp ')'       { $$ = $2; }
    | '-' term          { $$ = newast('M', $2, NULL); }
    ;
%%
