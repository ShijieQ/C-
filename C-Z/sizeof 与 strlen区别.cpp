//sizeof �����ڴ��С��strlen ����ʵ��ռ�ô�С 
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

