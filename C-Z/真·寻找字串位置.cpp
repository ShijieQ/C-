#include <stdio.h>
#include <string.h>
int main()
{
	int i,cota=0,cotb=0,n,res;
	char a[100],b[100];
	scanf("%s%s",a,b);
	cota=strlen(a);
	cotb=strlen(b);
	for(i=0;i<cota;i++)
	{
		if (a[i]==b[0])
		{
			for(n=1;n<cotb;n++)
			{
				if(b[n]==a[n+i])
				{
					res=i+1;
				}
			}
		}
	}
	printf("%d",res);
	return 0;
}
