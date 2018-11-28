#include<stdio.h>
#include<string.h>
int count = 99;
int fibs(int a[],int b[])
{
	int c[2006];
	for(int i = 0;i < 2006;i++)
	{
		if(a[i]+b[i]>=0)
		{
	  		c[i] = (a[i]+b[i]) % 10;
	  		c[i+1] += 1;
		}
		else c[i] = a[i] + b[i];
	}
}
int main()
{
	int a[2006],b[2006];
	int i;
	int c[2006];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	a[0] = 1;b[0] = 1;
	for(;count >= 0;count--)
		
	for(int j = 2006; j >= 0; j--)
		printf("%d",c[j]);
}

