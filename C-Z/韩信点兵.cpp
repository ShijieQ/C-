#include<stdio.h>
int main()
{
	int n,a,b,c,kase = 0;
	while(scanf("%d %d %d",&a,&b,&c) == 3)
	{
		int noanswer = 1;
		for(n = 10;n <= 100;n++)
		 if(n % 3 == a &&n % 5 == b &&n % 7 == c)
		 {
		 	printf("Case %d: %d\n",++kase,n);
		 	noanswer = 0;
		 	break;
		 }
		if(noanswer)
		 printf("Case %d: No answer\n",++kase);
	}
	return 0;
 } 
