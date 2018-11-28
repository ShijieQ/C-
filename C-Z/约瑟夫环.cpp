#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
int main()
{
	int n,m,count = 1;
	scanf("%d %d",&n,&m);
	int *a = (int *) malloc(sizeof(int)*n);
	memset(a,1,sizeof(a));
	int out = n;
	for(int i = 0; ; i++)
	{
		while(a[i] == 0)
		{
			i++;
			if(i >= n)
				i = 0;
		}
	//	printf("Time used = %.2f\n",(double)clock) / CLOCKS_PER_SEC);
		a[i] = count;
		if(count == m)
		{
			a[i] = 0;
			count = 1;
			out--;
		}
		else count++;
		for(int j = 0; j < n; j++)
			printf("%3d",a[j]);
		printf("\n");
		if(out == 1) break;
	}
	for(int j = 0; j < n; j++)
		if(a[j] != 0)
			printf("%d",j+1);
}


