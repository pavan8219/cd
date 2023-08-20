#include<stdio.h>
char productions[10][10];
int n;
void addToResult(char result[],char val)
{
	int i;
	for( i=0;result[i]!='\0';i++)
	{
		if(result[i]==val)return;
	}
	result[i]=val;
	result[i+1]='\0';
}

void first(char * result,char c)
{
	char subresult[20];
	int foundEpsilon;
	subresult[0]='\0';
	result[0]='\0';

	if(c>=97 && c<=122)
	{
		addToResult(result,c);
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(productions[i][0]==c)
		{
			if(productions[i][3]=='#')addToResult(result,'#');
			else
			{
				int j=3;
				while(productions[i][j]!='\0')
				{
					foundEpsilon=0;
					first(subresult,productions[i][j]);
					for(int k=0;subresult[k]!='\0';k++)if(subresult[k]!='#') addToResult(result,subresult[k]);
					for(int k=0;subresult[k]!='\0';k++)if(subresult[k]=='#')foundEpsilon=1;
					if(!foundEpsilon)break;
					j++;
				}
				if(productions[i][j]=='\0') addToResult(result,'#');
			}
		}
	}
	return;
}

void follow(char *result,char c)
{
	char subresult[20];
	int foundEpsilon=0;
	subresult[0]='\0';
	result[0]='\0';

	if(c==productions[0][0])addToResult(result,'$');
	for(int i=0;i<n;i++)
	{
		int j=3;
		while(productions[i][j]!='\0')
		{
			if(productions[i][j]==c)
			{
/*				if(c=='B')
				{
					printf("%d %d 	",i,j);
				}*/
				int l=j+1;			
				while(productions[i][l]!='\0')
				{
					first(subresult,productions[i][l]);
					for(int k=0;subresult[k]!='\0';k++)if(subresult[k]!='#') addToResult(result,subresult[k]);
					for(int k=0;subresult[k]!='\0';k++)if(subresult[k]=='#')foundEpsilon=1;
					if(!foundEpsilon)break;
					foundEpsilon=0;
					l++;
				}
				if(productions[i][l]=='\0' && productions[i][j]!=productions[i][0])
				{
					follow(subresult,productions[i][0]);
					for(int k=0;subresult[k]!='\0';k++) addToResult(result,subresult[k]);
					break;
				}				
			}
			j++;
		}
	}
	return;	
}
int main()
{
	char result[20];
    printf("enter no of productions");
	scanf("%d",&n);
	int y;
	printf("enter productions");
	for(int i=0;i<n;i++)scanf("%s",productions[i]);
	int visit[100];
/*	follow(result,'B');
	for(int j=0;result[j]!='\0';j++)printf("%c ",result[j]);*/
	for(int i=0;i<100;i++) visit[i]=0;
	for(int i=0;i<n;i++) visit[productions[i][0]]=1;
	printf("NonTe		first 		follow\n");
	for(int i=0;i<100;i++)if(visit[i]==1)
	{
		printf("%c 		",i);
		first(result,i);
		for(int j=0;result[j]!='\0';j++)printf("%c ",result[j]);
		printf("		");
		follow(result,i);
		for(int j=0;result[j]!='\0';j++)printf("%c ",result[j]);
		printf("\n");
	}
}