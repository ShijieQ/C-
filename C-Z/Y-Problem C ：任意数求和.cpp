/*Problem C:
	输入任意N个数，并求和 */
#include<stdio.h>
int main()
{
	int a,sum = 0;
	scanf("%d",&a);
	for(int i = 1; i <= a; i++)
	{
		int b;
		scanf("%d",&b);
		sum = sum + b;
	}
	printf("%d\n",sum);
 } 
