#include<stdio.h>
void _____(int n,int m);
int main()
{
	int m,n;//n为十进制数，m为新进制。
	do
	{
		scanf("%d %d",&n,&m);
	}while(m < 2);
	_____(n,m);
}
void _____(int n,int m)
{
	int s,a;
	s = n % m;
//	a = n / m;
	if(n/m) 
		_____(n/m,m);
	else 
	{
		if(s < 10) 
			printf("%d",s);
		else
			printf("%c",s+55);
		return ;
	}
	if(s < 10) 
			printf("%d",s);
		else
			printf("%c",s+55);
}
