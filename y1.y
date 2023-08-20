%{
	#include<stdio.h>
	void yyerror();
	int yylex(void);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%% 

E : T {printf("result is %d",$$);
        return 0;}
T : T '+' T {$$=$1+$3;}
  | T '-' T {$$=$1-$3;}
  | T '*' T {$$=$1*$3;}
  | T '/' T {$$=$1/$3;}
  | T '%' T {$$=$1%$3;}
  |NUM {$$=$1;}

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