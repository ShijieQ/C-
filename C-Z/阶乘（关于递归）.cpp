//递归在阶乘运算中的运用
/*#include<stdio.h>
double Fact(int a)
{
	if(a == 0)
	{return (1.0);}
	return (a * Fact(a-1));
}
int main()
{
	int a;
	double t;
	printf("Please input a number:");
	scanf("%d",&a);
	if(a < 0)
	{a = -a;}
	t = Fact(a); 
	printf("The answer is %d .\n",t);
	return 0;
}*/
//先调用，后定义测试 
#include<stdio.h>
double Fact (int a);
int main()
{
	int a;
	double t;
	printf("Please input a number:");
	scanf("%d",&a);
	if(a < 0)
	{a = -a;}
	t = Fact(a); 
	printf("The answer is %.2lf .\n",t);
	return 0;
}
double Fact(int a)
{
	if(a == 0)
	{return (1.0);}
	return (a * Fact(a-1));
}
/*
#include<stdio.h>
double Fact (int n)
{
	if (!n)
	 return (1.0);
	return (n * Fact(n - 1));
}
int main()
{
	int n;
	double t;
	printf("Please input n:\n");
	scanf("%d",&n);
	if (n < 0)
	  n = - n;
	t = Fact(n);
	printf("%d! = %lf\n",n,t);
	return 0;
}
*/
