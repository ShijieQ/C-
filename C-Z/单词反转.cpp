#include<stdio.h>
int main()
{
	char str[100];
	int i,j; 
	gets(str);
	for(i = 0;i < 100;i++)
	{
		if(str[i] == '\0')
		  break;
	}
	for(j = i - 1;j >= 0;j--)
	{
		printf("%c",str[j]);
	}
	return 0;
 } 
