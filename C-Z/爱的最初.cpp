#include<stdio.h>
int calate(int a)
{
	a = a + 32;
	return (a);
}
int main()
{
	char a;
	char c;
	scanf("%c",&a);
	c = calate(a);
	printf("the answer is %c.\n",c);
	return 0;
 } 
