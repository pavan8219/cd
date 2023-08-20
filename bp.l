%option noyywrap
%{
	#include<stdio.h>
	#include"bp.tab.h"
%}

%%
[a-z]+ {return id;}
[()] {return yytext[0];}
[\n] {return 0;}
%%
