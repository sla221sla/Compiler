%{
#include<stdio.h>

%}
E ""
a /a
b /b
c /c
%%
((b|c)|(a|ba)(c|bb))*({E}|a(a|ba)*({E}|b)) {printf("Follows the pattern\n");}
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
