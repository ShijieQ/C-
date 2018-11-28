#include<stdio.h>
int main()
{
	char a, b, c;
	a = getchar();
	getchar();
	b = getchar();
	putchar(a);
	putchar(b);
	putchar('\n');
	printf("%c%c",a,b);
	putchar('\t');
	putchar('\f'); 
	putchar('\?'); 
	putchar('g');
	return 0;
 } 
