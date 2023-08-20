%{
	#include<stdio.h>
	int k=0;
%}

%token id

%% 
S : E {printf("count id %d",k);}
E : '(' E ')' E {k++;}
  | id{}
  |{}
%%
int main()
{
  printf("enter");
  yyparse();
  return 0;
  }
 void yyerror()
 {
   printf("invalid");
   }