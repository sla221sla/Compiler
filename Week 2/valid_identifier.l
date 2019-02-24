%{
#include<stdio.h>
//#include "yy.tab.h"
//this checks for the longest prefix where the rule matches and echoes the rest
//using definition name inside rules, use "{}"
//if the rule on top is matched it won't check the ones below

%}

letters [a-zA-Z]
digits [0-9]

%%
{letters}({letters}|{digits})* {printf("This is a valid identifier");}
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
