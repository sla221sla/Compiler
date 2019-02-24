%{
#include<stdio.h>
//#include "yy.tab.h"
//this checks for the longest prefix where the rule matches and echoes the rest
//using definition name inside rules, use "{}"
//if the rule on top is matched it won't check the ones below

%}
d1 (a|b|c)*
d2 xyy

%%
{d1}{d2} {printf("...xyy\n");}
(abc){d1}(abb) {printf("abc...abb\n");}
{d1}(abb) {printf("...abb\n");}
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
