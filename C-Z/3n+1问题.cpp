#include<stdio.h>
void noname(int a);
int main()
{
	int a;
	while(printf("Please input a number:"),scanf("%d",&a) != EOF)
	  noname(a);
}
void noname(int a)
{
	static int count = 0;
	if(a % 2 == 1)
		a = 3*a + 1;
	else a = a / 2;
	count++;
	if(a == 1) 
		{
			printf("The time is %d.\n",count);
			count = 0;
		}
	else 
		noname(a);
}
