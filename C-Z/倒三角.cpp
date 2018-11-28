#include<stdio.h>
int main()
{
	int a;
	while(printf("Please input the number of the line:"),scanf("%d",&a) == 1)
	{
		for(int i = a;i > 0;i--)
		{
			for(int b = 0;b < a - i; b++)
				printf(" ");
			for(int c = 0;c < 2*i - 1;c++)
				printf("#");
			printf("\n");
		}
		printf("\n");
	}
 } 
