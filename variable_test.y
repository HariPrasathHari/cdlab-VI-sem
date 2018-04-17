%{
#include<stdio.h>
/* This YACC program is for recognising the Expression*/
%}
%token ID INT FLOAT DOUBLE
%%
D:T L
;
L:L ID
|ID
;
T:INT
|FLOAT
|DOUBLE
;
%%
extern FILE *yyin;
main()
{
do
{
yyparse();
}while(!feof(yyin));
}
yyerror(char*s)
{
}
