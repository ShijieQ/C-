#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
	int n,m,count = 0;
	scanf("%d %d",&n,&m);
	int *a = (int *) malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++) a[i] = 0;
	int out = n;
	for(int i = 0; ; i++)
	{
		if(i == n) i = 0;
	//	printf("Time used = %.2f\n",(double)clock() / CLOCKS_PER_SEC);
		if(a[i] == 0)
			count++;
		else continue;
		if(count % m == 0)
		{
			a[i] = 1;
			out--;
		}
		if(out == 1) 
			break;
	}
	for(int i = 0;i < n; i++)
		if(a[i]==0) 
			printf("%d\n",i+1);
}


