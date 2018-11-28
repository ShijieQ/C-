#include<stdio.h>
#include<string.h>
int main()
{
	int a[100],b[100];
	a[100] = {0};
	memset(a,0,sizeof(a));
	for(int i = 0;i < 10;i++)
	 printf("%d",a[i]);
	 printf("\n");
	for(int i = 0;i < 10;i++)
	 printf("%d",b[i]);
}
