#include<stdio.h>
int main()
{
	int N,M,m; 
	scanf("%d",&N);
	for(int j=0;j<N;j++)
	{
		int sum = 0;
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			scanf("%d",&m);
			sum+=m;		
		}
		if(!j) 
		{
			printf("%d\n",sum);
		}
		else
			printf("\n%d\n",sum);
	}
	return 0;
}

