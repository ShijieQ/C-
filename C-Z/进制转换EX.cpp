#include<stdio.h>
void MultiBase(int n,int B);
int main()
{
	int n,B;
	printf("Please input a number and system:"); 
	do
	{
		scanf("%d %d",&n,&B);
	}while(n <= 0||B <= 1||B >= 16);  
    MultiBase(n,B);
	printf("\n");
	main();
	return 0;
 } 
void MultiBase(int n,int B)
{
	int m;
	if(n)
	{
		MultiBase(n/B,B);
		m = n % B;
		if(m < 10)
		  printf("%d",m);
		else
		  printf("%c",m+55);
	}
}
