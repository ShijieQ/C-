#include<stdio.h>
//��������ʵ������λ�ý��� 
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
