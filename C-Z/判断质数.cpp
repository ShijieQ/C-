#include<stdio.h>
#include<math.h>
int main()
{
	int a,i;
	printf("Please input a positive number:");
	do 
	{
		scanf("%d",&a);
	}while (a <= 0);
	int b = (int) sqrt(a);
	a = 999999;
	if (b == 1)
	{printf("This is not a zs.");}
	else
	{
		for(i = 2;i <= b;i++)
		{
			if(b % i == 0)
			{
				break;
			}
		}
		if(i > b)
		{
			printf("This is a zs.");
		}
		else
		{
			printf("This is not zs.");
		}
	}
	return 0;
} 
