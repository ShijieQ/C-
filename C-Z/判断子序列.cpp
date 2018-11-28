#include<stdio.h>
#include<string.h>
int main()
{
	int s,t,j,i;
	char str1[100000],str2[100000];
    while(scanf("%s",&str1),scanf("%s",&str2) != EOF)
    {
	s = strlen(str1);
	t = strlen(str2);
	i = 0; j = 0;
	do
	{
		if(str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else 
		{
			j++;
		}
	}while(i < s&&j < t);
	if(i == s) 
		printf("Yes\n");
	else printf("No\n");
	}
}
