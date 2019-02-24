%{
#include<stdio.h>

%}
d1 (x|y|z)*
d2 xy
d3 yyxz

%%
{d2}{d1}z{d1}x{d1}{d3} {printf("Follows the pattern\n");}
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
