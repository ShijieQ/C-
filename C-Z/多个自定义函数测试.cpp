#include<stdio.h>
int gys (int m,int n);
void drawline ( );
int main ()
{
	int m,n,j;
	printf("Please input two numbers:");
	scanf("%d£¬%d",&m,&n);
	drawline ( );  
	printf("The answer is %d.\n",gys (m,n) );
	return 0;
} 
int gys (int m,int n)
{
	int c;
	do
	{
		c = m % n;
		m = n;
		n = c; 
	} while ( c != 0 ); 
	return m;
}
void drawline ( )
{
	int i;
	for( i = 1;i <= 32;i++)
	{
		printf("-");
	}
	printf("\n");
	return ;
}

