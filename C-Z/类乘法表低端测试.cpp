#include<stdio.h>
int main()
{
	int a,b,c,d;
	char e;
	printf("Please input a number:");
	scanf("%d",&c);
	for( a = 1;a <= c;a++)
	{
	/*	for(d = c - a;d > 0;d--)
		{  
			printf(" ");
		}  */
		for(b = 1;b <= a;b++)
		{
			printf("%c",b+64);
		}
		printf("\n");
	}
	printf("Continue or no?(Y or N):");
	getchar ();
	scanf("%c",&e);
	if(e == 'Y')
	{
		for( a = 1;a <= c;a++)
	  {
		for(d = c - a;d > 0;d--)
		{  
			printf(" ");
		}  
		for(b = 1;b <= a;b++)
		{
			printf("%c",b+64);
		}
		printf("\n");
	  }
    }
	else 
	{
		printf("Goodbye.\n");
	}   
} 
