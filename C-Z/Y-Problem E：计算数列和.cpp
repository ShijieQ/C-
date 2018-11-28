/*Problem E:
	计算数列和2/1，3/2，5/3，8/5... */
#include<stdio.h>
int main()
{
	int n;
	int a = 1,b = 2;//每一项的式子. 
	double sum;//总和. 
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		int bet;//中间变量用于存储a的值. 
		sum = double (b) / a + sum;//由于b,a都为整型，乘小数使其变为浮点型. 
		bet = b;
		b = a + b;//通过规律找到每一项与前一项之间的关系.
		a = bet; 
	}
	printf("s=%.2f\n",sum); 
}
