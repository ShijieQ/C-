#include<stdio.h>
int reverse(int n);
int main()
{
	int a;
	while(1)
	{
		scanf("%d",&a);
		printf("%d\n",reverse(a));
	}
}
int reverse(int n)
{
	int i;
	int number,result = 0;
	if(n == 0) return 0;
	else if(n < 0) number = -n;
	else number = n;
	while(number)
	{
		result = result * 10;
		i = number % 10;
		number = number / 10;
		result = i + result;
	}
	if(n < 0) return -result;
	else return result;
}
