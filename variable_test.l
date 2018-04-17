%{
/* This LEX program returns the tokens for the Expression */
#include "y.tab.h"
%}
%%
"int " {printf("\nint is a KEYWORD");}
"float " {printf("\nfloat is a KEYWORD");}
"double " {printf("\ndouble is a KEYWORD");}
[a-zA-Z]*[0-9]* {printf("\nIdentifier is %s",yytext);}
return yytext[0];
%%
int yywrap()
{
return 1;
}
