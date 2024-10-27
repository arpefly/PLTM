%{
#include <stdio.h>
%}

%%
[0-9]+              { printf("NUMBER\n"); }
[0-9]+(\.[0-9]+)?   { printf("FLOAT NUMBER\n"); }
[a-zA-Z]+           { printf("STRING\n"); }
"+"                 { printf("PLUS\n"); }
"-"                 { printf("MINUS\n"); }
"*"                 { printf("TIMES\n"); }
"/"                 { printf("DIVIDE\n"); }
"|"                 { printf("ABS\n"); }
"("                 { printf("OBRACE\n"); }
")"                 { printf("EBRACE\n"); }
"="                 { printf("EQUAL\n"); }
[ \t]+              { printf("SPACES OR TABS\n"); }
.                   { printf("Mystery character %s\n", yytext); }
%%
