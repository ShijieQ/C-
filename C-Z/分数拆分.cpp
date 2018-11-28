#include<stdio.h>
int main()
{
	int n,x,y;
	while(scanf("%d",&n) != EOF)
	{
		int a[1000],b[1000];
		int count = 0;
		for(y = n + 1; y < 2*n; y++)
			if((n * y) % (y - n) == 0)
			{
				x = (n * y)/(y - n);
				a[count]= x;
				b[count]= y;
				count++;
			}
//		if(n % 2 == 0)
			printf("%d\n",count+1);
//		else
//			printf("%d\n",count);
		for(int j = 0; j < count; j++)
			printf("1/%d = 1/%d + 1/%d\n",n,a[j],b[j]);
//		if(n % 2 == 0) 
			printf("1/%d = 1/%d + 1/%d\n",n,n*2,n*2);
	}
}
