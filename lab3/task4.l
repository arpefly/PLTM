%option noyywrap

%{
#include "task4.tab.h"
%}

%%
[0-9]+(\.[0-9]+)?   { yylval.d = atof(yytext); return NUMBER; }
[-+*/()]            { return yytext[0]; }
\n                  { return EOL; }
[ \t]               { /* ignore whitespace */ }
.                   { printf("Mystery character %c\n", *yytext); }
%%
