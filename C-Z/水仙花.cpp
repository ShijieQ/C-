#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	while(scanf("%d",&a) != EOF)
	{
		b = a / 100;
		c = a / 10 %10;
		d = a % 10 %10;
		if(a == pow(b,3) + pow(c,3) +pow(d,3))
		   printf("Yes\n");
		else
		   printf("No\n");
	}
	return 0;
 } 
