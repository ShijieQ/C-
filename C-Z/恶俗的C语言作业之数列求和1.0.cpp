#include<stdio.h>
#include<math.h>
double fun(int a);
int main()
{
	double x,sum = 0;
	int i = 1;
	scanf("%lf",&x);
	double j = (pow((-1),i+1) * pow(x,i))/fun(i);
	while(fabs(j) > 0.00001)
	{
		j = (pow((-1),i+1) * pow(x,i))/fun(i);
		sum = j + sum;
	//	printf("%.2f %d\n",sum,fun(i));
		i++;
	}
	printf("sum=%.2f",sum);
	
}
double fun(int a)
{
	double b=1.0;	
	while(a > 0)
	{ 
	  b = a * b;
	  a--;
	} 
	return (b);
}
