#include<stdio.h>
int main()
{
	char a;
	int c,d,e;
	printf("Please input a letter:");
	scanf("%c",&a);
	for(c = 65;c <= a;c++)
	{
		for(d = a - c; d > 0;d--)
		{
			printf(" ");
		}
		for(d = 65;d < c;d++)
		{
			printf("%c",d);
		}
		for(e = c;e >= 65;e--)
		{
		    printf("%c",e);	
		}
		printf("\n");
	}
	
 } 
