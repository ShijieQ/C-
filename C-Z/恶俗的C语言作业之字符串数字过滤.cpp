#include<stdio.h>
#include<string.h>
int main()
{
	char str[10000],str1[10000];
	int j = 0;
	scanf("%s",&str);
	for(int i = 0; i < strlen(str); i++)
		if(str[i] >= '0' && str[i] <= '9')
			str1[j++] = str[i];
	printf("%s",str1);
	return 0;
}
