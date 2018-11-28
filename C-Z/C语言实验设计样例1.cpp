#include<stdio.h>
int main()
{
	int a;
	double b,sum = 0;
	for(a = 1;a <= 5000;a++)
	{
		b = 1 / (double)a;
		if(b < 1e-6) break;
		if(a % 2 == 0) sum -= b;
		else sum += b;
	}
	printf("sum = %f\n",sum);
	return 0;
 } 
