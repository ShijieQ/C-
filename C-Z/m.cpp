#include<stdio.h>
int ____(int n,int m);
int main()
{
	int a,b;
	scanf("%d %d",&n,&m);//n为数，m为进制
	printf("%d",____(n,m));
	return 0; 
}
int ____(int n,int m)
{
	int a,sum;
	for(int i = 0; n != 0; i++)
	{
		a = n % 10;
		n = n / 10;
		sum += a * pow(m,i);
	}
	return sum;
}
