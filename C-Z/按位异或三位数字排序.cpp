#include<stdio.h>
int main()
{
	int a,b,c;
	for(;;) 
	{
		printf("Please input three numbers:");
		scanf("%d %d %d",&a,&b,&c);
		if(a > b) {a ^= b ^= a ^= b;}
		if(a > c) {a ^= c ^= a ^= c;}
		if(b > c) {b ^= c ^= b ^= c;}
		printf("%d < %d < %d\n",a,b,c);
	}
	return 0;
} 
