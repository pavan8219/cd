%option noyywrap
%{
	#include<stdio.h>
	#include"bd.tab.h"
%}

%%
[01] {yylval=atoi(yytext); return NUM;}
[\n] {return 0;}
%%
