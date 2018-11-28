 #include<stdio.h>
#include<math.h>
int main()
{
	int m,t/*t为计数用*/;
	float k,s,a,b;
	s=0;
	scanf("%d",&m);
	 
	for(t=1;t<=m;t++)
	{
	b=1;//阶乘
	for(a=1;a<=t;a++)
	{
		
		b=a*b;
	}//阶乘 
	k=(pow(m,t))/b;//每一项 
	printf("%f",k);
	s=s-k*(pow((-1),t));
	}
	printf("%f",s);
	return 0;
}
