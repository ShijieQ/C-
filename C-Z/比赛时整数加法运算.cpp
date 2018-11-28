#include<stdio.h>
//竞赛时不定个数整数加法运算 
int main()
{
	int a, b = 0, n, i;
	printf("please input a number:");
	while(scanf("%d",&n) != EOF)
	{
	  if( n == 0)
	  {
	  	continue;
	  }
	  else
	  {
	   for(i = 1; i <= n; i++)
	   {
	    scanf("%d",&a);
		b= a + b;
       }   
       printf("The sum = %d\n",b);
      }
    }
	return 0;
} 
