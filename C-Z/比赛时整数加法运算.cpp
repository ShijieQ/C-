#include<stdio.h>
//����ʱ�������������ӷ����� 
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
