/*Problem A:
	������� */
#include<stdio.h>
int main()
{
	int a,i,b,judge = 1,sum = 0;
	scanf("%d",&a);//5 (�������룩 
	for(i = 1; i <= a; i++)
	{
		scanf("%d",&b);//3 5 ���������룩 
		for(int j = 2; j < b; j++)
		{
			if(b % j == 0)
				judge = 0;
		}
		if(judge == 1) 
		{
			printf("%d ",b);
			sum = sum + b;
		}
		judge = 1;
	}
	printf("%d",sum);
}
