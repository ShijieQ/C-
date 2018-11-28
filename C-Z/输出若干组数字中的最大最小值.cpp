#include<stdio.h>
int main()
{
	int a,b,min,max,i;
	scanf("%d%d",&a,&b);
	min = b;
	max = b;
	for(i = 1;i < a;i++)
	{
		scanf("%d",&b);
        if(b < min)
         min = b;
        else if(b > max)
         max = b;
    }
    printf("%d %d",min,max);
    return 0;
 } 
