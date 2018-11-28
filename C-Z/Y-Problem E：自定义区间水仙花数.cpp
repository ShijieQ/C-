#include<stdio.h>
#include<math.h>
void judgeflower(int a);
int main()
{
	int m,n;
	do
	{
		scanf("%d %d",&m,&n);
	}while(m < 1 || n > 1000 || m > n);
	for(int i = m; i <= n; i++)
		judgeflower(i);
	return 0;
}
void judgeflower(int a)
{
	if(a == 1)
		printf("%d",a);
	if(a >= 10&&a <= 99)
		if(pow(a%10,3) + pow(a/10,3) == a)
			printf("%3d",a);
	if(a >= 100&&a <= 999)
		if(pow(a/100,3) + pow(a/10%10,3) + pow(a%10,3) == a)
			printf("%4d",a);
	if(a == 1000)
		printf("%5d",a);
} 
