#include<stdio.h>
int main()
{
	int a;
	float b;
	scanf("%d %f",&a,&b);
	if(((int)(a*0.1*b))%10 >= 5)
	  printf("%d",((int)(a*0.1*b))-((int)(a*0.1*b))%10 + 10);
	else
	  printf("%d",((int)(a*0.1*b))-((int)(a*0.1*b))%10);
	return 0;
 } 
