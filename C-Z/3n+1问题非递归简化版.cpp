#include<stdio.h>
#include<time.h>
/*keep it simple and stupid.*/
int main()
{
	long long int a;
	int count = 0;
	while(printf("Please input a number:"),scanf("%lld",&a) != EOF)
	{
		while(a > 1)
		{
			if(a % 2 == 1) a = 3 * a + 1;
			else a = a / 2;
			count++;
		}
		printf("The time is %d.\n",count);
		printf("The time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);//��ȡ�������е����ڵ�ʱ�䡣 
		count = 0;
	}
}
