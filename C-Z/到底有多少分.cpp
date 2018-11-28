#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c = 0,i,j,sum;
	char str[80];
	scanf("%d",&a);
	for(i = 0;i < a;i++)
	{
		scanf("%s",&str);
		b = strlen(str);
		sum = 0;
		for(j = 0;j < b;j++)
		{
			if(str[j] == 'O')
			{
				c = c + 1;
			}
			else
			{
				c = 0;
			}
			sum = c + sum;
		}
		c = 0;
		printf("%d\n",sum);
	}
/*	for(i = 0;i < a-1;i++)
	{
	  printf("%d\n",sum[i]);
    }
    printf("%d",sum[a]);*/
} 
