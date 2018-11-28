#include<stdio.h>
int main()
{
	char a,b,c,d;
	a = getchar ();
	b = getchar ();
	scanf("%c%c",&c,&d);
	putchar(a);
	putchar(b);
	printf("%c%c",c,d);
	return 0;
	//回车属于字符常量，被getchar记录。 
 } 
