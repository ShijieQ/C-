#include<stdio.h>
#include<string.h>
int main()
{   /*broken broad.*/
	int last,c,next[100009];
	char a[100009];
	while(scanf("%s",a+1) != EOF)
	{
		last = c = 0;
		next[0] = 0;
		for(int i = 1;i <= strlen(a+1);i++)
		{
			if(a[i] == '[')
				c = 0;
			else if(a[i] == ']')
				c = last;
			else
			{
				next[i] = next[c];
				next[c] = i;
				if(c == last)
					last = i;
				c = i;
			}
		}
		for(int i = next[0];i != 0;i = next[i])
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
