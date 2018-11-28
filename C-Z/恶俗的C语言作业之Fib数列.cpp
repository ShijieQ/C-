#include<stdio.h>
int main()
{
	int Fib[101],i;
	Fib[0] = 1;
	Fib[1] = 1;
	for(i = 2;i <= 99;i++)
	{
		Fib[i] = Fib[i-1] + Fib[i-2];
	}
	for(i = 0;i <= 99;i++)
	{
		printf("%5d\n",Fib[i]);
	} 
	printf("%d",Fib[9]);
}
