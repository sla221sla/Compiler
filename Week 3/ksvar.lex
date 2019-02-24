%{
#include<stdio.h>
%}
ch [a-zA-Z@$#%0-9]
d [0-9]
var {ch}({ch}|{d})*
sp [" "]
e ""
rs {var}[>|<|<\=|>\=]{var}
sh {sp}*{var}{sp}*((\+\=)|(\-\=)|(\*\=)|(\/\=)){sp}*{var}{sp}*
op (\+|\-|\*|\/)
cs {sp}*({var}|d+){sp}*{op}{sp}*({var}|d+){sp}*({op}{sp}*({var}|d+){sp}*)+
br (\({cs}\))+

%%
{rs}; {printf(" Compound %s", yytext);}
{sp}*{var}{sp}*\={sp}*({var}|d+){sp}*{op}{sp}*({var}|d+){sp}*; {printf(" Simple");}
{sp}*{var}{sp}*\=({cs}|{br}); {printf(" Compound");}

{sh}; {printf(" Compound%s", yytext);}

{sp}*printf\({sp}*\".*\"{sp}*(\,.*)*\){sp}*; {printf("%s ",yytext);}
{sp}*scanf\({sp}*\".*\"{sp}*(\,&?{var})+\){sp}*;  {printf("%s ",yytext);}
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
