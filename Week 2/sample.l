%{
#include<stdio.h>
//#include "yy.tab.h"
%}
a \a
b \b
c \c

//rule {action}
//this checks for the longest prefix where the rule matches and echoes the rest
%%
(a|b|c)* {printf("VALID STRING\n");}
. {printf("Some other string\n")}
%%
int yywrap()
{
return 1;
}
int main()
{
yylex();
}
