#include<stdio.h>
int zuidagongyueshu(int a,int b);
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",zuidagongyueshu(a,b));
}
int zuidagongyueshu(int a,int b)
{
	int c;
	c = a % b;
	if(c) zuidagongyueshu(b,c);
	else return b;
}
