/*Problem D:
	N������������Сֵ */
#include<stdio.h>
int main()
{
	int a,n,max = -10000000,min = 10000000;
	scanf("%d",&n); 
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a);
		if(a > max)
			max = a;
		if(a < min)
			min = a;
	}
	printf("max=%d,min=%d",max,min);
} 
