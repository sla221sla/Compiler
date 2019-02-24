%{
#include<stdio.h>
//#include "yy.tab.h"
//Epsilon represented by ""


%}

e ""
digit [0-9]
digits {digit}{digit}*
optionalFraction (\.{digits})|{e}
optionalExponent (E[+-]{digits})|{e}
number {digits}{optionalFraction}{optionalExponent}

%%

{number} {printf("Valid unsigned number\n");}
.* {printf("Some other string\n");}
%%

int yywrap()
{
return 1;
}
int main()
{
yylex();
}
