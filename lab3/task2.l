%{
#include "task2.tab.h"
%}


%%
[0-9]+  { yylval = atoi(yytext); return NUMBER; }
"+"     { return ADD; }
"-"     { return SUB; }
\n      { return EOL; }
[ \t]   { /* ignore whitespace */ }
.       { printf("Mystery character %c\n", *yytext); }
%%

int yywrap(){
    return 1;
}
