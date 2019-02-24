
%{
#include<stdio.h>

%}
E ""
a /a
b /b
c /c
%%
(a|b)*({E}|c(b|c)*({E}|(a|c)*))  {printf("Follows the pattern\n");}
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
