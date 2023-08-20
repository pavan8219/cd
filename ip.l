%option noyywrap
%{
	#include<stdio.h>
	#include"ip.tab.h"
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUM;}
[+ - * /] {return yytext[0];}
[\n] {return 0;}
%%
