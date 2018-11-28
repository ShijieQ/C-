#include<stdio.h>
#include<math.h>
double fun(int a);
int main()
{
	double x,sum = 0;
	int i = 1;
	scanf("%lf",&x);
	double j,k = pow(x,i)/fun(i);
	double a,b;
	while(k > 0.00001)
	{
		a = pow(-1,i+1);
		b = pow(x,i);
		j = a * b/fun(i);
		k = b / fun(i);
		sum = j + sum;
		i++;
	}
	printf("sum=%.2f",sum);
	
}
double fun(int a)
{
	double b = 1.0;
	while(a > 0)
	{ 
	  b = a * b;
	  a--;
	} 
	return (b);
}
