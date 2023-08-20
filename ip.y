%{
	#include<stdio.h>
	void yyerror();
	int yylex(void);
%}

%token NUM

%% 
E : E '+' T {printf("+");}
  | T {}
T : T '*' F {printf("*");}
  |NUM {printf("%d",yylval);}
F :NUM {printf("%d",yylval);}
%%

int main()
{
  printf("enter expr:");
  yyparse();
  return 0;
  }

void yyerror()
{
   printf("invalid");
   }