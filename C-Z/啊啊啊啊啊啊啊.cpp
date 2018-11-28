#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void random(int a[])
{
	srand(time(0));
	for(int i = 0; i < 1000; i++)
	{
		a[i] = rand()%10001+1;
	}
}
int main()
{
	int a[1000];
	random(a);
/*	for(int i = 0; i < 1000; i++)
	{
		printf("%5d",a[i]);
	} */ 
	sort(a,a+1000); 
}
