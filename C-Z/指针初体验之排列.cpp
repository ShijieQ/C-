#include<stdio.h>
#include<string.h>
double fuck(int *a);
int main()
{
	int a[10];
	for(int i = 0; i < 10; i++)
		scanf("%d",&a[i]);
	printf("%.2f\n",fuck(a));
	for(int i = 0; i < 10; i++)
	{
		printf("%5d",a[i]); 
	}
	return 0;
}
double fuck(int *a)
{
	int j = 0;
	int b[10],sum;
	double average;
	for(int i = 0; i < 10; i++)
	{
		sum += a[i];
	}
	average = double (sum) / 10;
	for(int i = 0; i < 10; i++)
	{
		if(a[i] < average)
		{
			b[j++] = a[i];
			a[i] = -1;
		}
	}
	for(int i = 0; i < 10; i++)
	{
		if(a[i] != -1)
			b[j++] = a[i];
	}
	for(int i = 0; i < 10; i++)
		a[i] = b[i];
	return average;
}
