#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int a[10000],b[10000];
		int count = 0;
		int m = n << 1;
		printf("%d\n",m);
		for(int i = n + 1; i <= m; ++i)
			if((i * n) % (i - n) == 0)
			{
				a[count]= i * n/(i - n);
				b[count]= i;
				count++;
			}
/*		if(n % 2 == 0)
			printf("%d\n",count+1);
		else
			printf("%d\n",count);*/
		for(int j = 0; j < count; j++)
			printf("1/%d = 1/%d + 1/%d\n",n,a[j],b[j]);
/*		if(n % 2 == 0) 
			printf("1/%d = 1/%d + 1/%d\n",n,n*2,n*2);*/
	}
}
