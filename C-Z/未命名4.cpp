#include<stdio.h>
#include<string.h>
int main( )
{
	int j,a,b,k,i;
	char A[129];
	scanf("%d",&j);
	for(k=0;k<j;k++)
	{
		a=b=0;
		scanf("%s",&A);
		for(i=0;i < strlen(A);i++)
		{
			if(A[i]=='(')
				a++;
			if(A[i]=='[')
				b++;
			if(A[i]==')')
				a--;
			if(A[i]==']')
				b--;
			A[i]='\0';
		}
		if(a == 0&&b == 0)
			printf("Yes\n");
		else
			printf("No\n");
		
	}
}
