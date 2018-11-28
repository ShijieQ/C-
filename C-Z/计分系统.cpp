#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x >= 90 && x <= 100)
	{
		printf("A");
	}	
	if(x >= 80 && x < 90)
	{
		printf("B");
	}
	if(x >= 70 && x < 80)
	{
		printf("C");
	}
	if(x >= 60 && x < 70)
	{
		printf("D");
	}
	if(x >= 0 && x < 60)
	{
		printf("E");
	}
	return 0;
} 
