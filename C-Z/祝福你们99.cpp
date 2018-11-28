#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("please input number: ");
	scanf("%d",&c);
	for(a = 1;a <= c ;a++)
	{
	 /*for(d = c - a;d > 0 ; d--)
	 {
	 	printf("             ");
	 } */
	 for(b = 1;b <= a ;b++) 
	 {
		printf("%-2d * %-2d = %-2d ",b,a,a*b);
	 }	
	 printf("\n");
	}
    return 0;
 } 
