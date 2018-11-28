#include<stdio.h>
int main()
{
	int a,b,kase;
	while(scanf("%d %d",&a,&b)==2 && a && b)
	{
		double sum = 0;
		for(;a <= b;a++)
		{
			double c = 1.0/a/a;
			//compared with "c = 1.0/(a*a)",use this sentence to avoid the overflow like "1.#INF0"
			sum += c;
		}
		printf("Case %d: %.5f\n",++kase,sum);
	}
	return 0;
 } 
