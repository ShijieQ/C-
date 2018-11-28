/*Problem F:
	¼ÆËãX^N(N¸öXÏà³Ë) */
#include<stdio.h>
int main()
{
	int n;
	double x,sum = 1.0;
	scanf("%lf %d",&x,&n);
	for(int i = 1; i <= n; i++)
	{
		sum = sum * x;
	}
	printf("%.2f",sum);
 } 
