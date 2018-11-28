//sizeof 测量内存大小，strlen 测量实际占用大小 
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int a,b;
	scanf("%s",&str);
	a = sizeof(str);
	b = strlen(str);
	printf("\asizeof = %d\nstrlen = %d\n\a",a,b);
	return 0;
} 

