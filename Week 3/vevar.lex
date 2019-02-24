%{
#include<stdio.h>
%}
c [a-zA-Z@$#%0-9]
d [0-9]
var {c}({c}|{d})*
sp [" "]
%%
{sp}*(int|float|char|double){sp}*({sp}*(""|\*)(({var}{sp}*(""|\[{d}*\])*)|({var}{sp}*(""|\[{d}*\])*={sp}*({d}*|(""|\&){var}|\'{c}\'|{d}*.{d}*|\{.*\}){sp}*))(\,|\;))* {printf("%s ",yytext);}
{sp}*printf\({sp}*\".*\"{sp}*(\,.*)*\){sp}*; {printf("%s ",yytext);}
{sp}*scanf\({sp}*\".*\"{sp}*\){sp}*;  {printf("%s ",yytext);}
.* {}
%%
int yywrap()
{
 return 1;
}
int main()
{
 yyin=fopen("c1.c","r");
 yylex();
 return 0;
}
