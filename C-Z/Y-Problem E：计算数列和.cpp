/*Problem E:
	�������к�2/1��3/2��5/3��8/5... */
#include<stdio.h>
int main()
{
	int n;
	int a = 1,b = 2;//ÿһ���ʽ��. 
	double sum;//�ܺ�. 
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		int bet;//�м�������ڴ洢a��ֵ. 
		sum = double (b) / a + sum;//����b,a��Ϊ���ͣ���С��ʹ���Ϊ������. 
		bet = b;
		b = a + b;//ͨ�������ҵ�ÿһ����ǰһ��֮��Ĺ�ϵ.
		a = bet; 
	}
	printf("s=%.2f\n",sum); 
}
