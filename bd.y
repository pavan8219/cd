%{
	#include<stdio.h>
	void yyerror(); 
%}

%token NUM

%% 
S : E {$$=$1; printf("%d",$$); return 0;}
E : E NUM {$$=(2*$1)+$2;}
  | NUM{$1=yylval;}
%%
int main()	
{
  printf("enter expr");
  yyparse();
  return 0;
  }
 void yyerror()
 {
    printf("invalid");
    }
