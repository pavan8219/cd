%option noyywrap
%{
	#include<stdio.h>
	#include"y1.tab.h"	
%}

%%
[0-9]+ {yylval=atoi(yytext);return NUM;}
[\n] {return 0;}
. {return yytext[0];}
%%
