#include<stdio.h>
void move(int a[]);
int main()
{
	int a[11]={1,2,3,4,5,6,7,8,9,10};
	int count;
	scanf("%d",&count);
	for(int i = 0; i < count; i++)
		move(a);
	for(int i = 0; i < 10; i++)
	{
		if(!i)
			printf("%d",a[i]);
		else
			printf(" %d",a[i]);
	}
}
void move(int a[])
{
	for(int i = 9; i >= 0; i--)
		a[i+1] = a[i];
	a[0] = a[10];
}
