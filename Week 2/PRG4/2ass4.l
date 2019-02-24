%{
#include<stdio.h>

%}

e ""
digit [0-9]
character [A-Z]|[a-z]
digits {digit}{digit}*
optionalFraction (\.{digits})|{e}
optionalExponent (E[+-]{digits})|{e}
number {digits}{optionalFraction}{optionalExponent}
operator [+-/*]
rem %
opexpression {number}{operator}{number}|{digits}{rem}{digits}
array \[.*\]
string \".*\"

%%

{number}|{opexpression}|{character}|{array}|{string} {printf("Valid\n");}
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
