#include<stdio.h>
//两个变量实现数字位置交换 
/*int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d",a,b);
	return 0;
} */
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	a ^= b ^= a ^= b;
	printf("%d %d",a,b);
	return 0;
} 
