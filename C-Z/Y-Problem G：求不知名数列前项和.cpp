/*Problem G:
	求前N项和1-2/3+3/5-4/7+5/9+... */
#include<stdio.h>
int main()
{
	int n;
	double sum = 0,x;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		x = double (i) / (2*i-1);//每一项. 
		if(i % 2 == 0) sum = sum - x;
		else sum = sum + x;
	}
	printf("%.2f",sum); 
} 
