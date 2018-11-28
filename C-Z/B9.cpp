#include<stdio.h>
int main()
{
	int a,b,i,k,m,c,j=0,r;
	int l1[100000]={0};
	int l2[100000]={0};
	while(1)
	{
	scanf("%d %d",&a,&b);
		c=0;
		j++;
		if(a==0&&b==0)
			return 0;
		for(i=0;i<a;i++)
			scanf("%d",&l1[i]);
		for(i=0;i<b;i++)
			scanf("%d",&l2[i]);
		printf("CASE# %d:\n",j);
		for(i=0;i<a;i++)
			{
				for(k=0;k<a-1;k++)
				{
					if(l1[k]>l1[k+1])
					{
						r=l1[k+1];
						l1[k+1]=l1[k];
						l1[k]=r; 
					}
				}
			 } 
		for(i=0;i<b;i++)
			{
				for(k=0;k<a;k++)
					{
						if(l1[k]==l2[i])
							{
									printf("%d found at %d\n",l2[i],k+1);
									c=1;
									break;
							}
							c=0; 
					}
				if(c==0)
					printf("%d not found\n",l2[i]);
			}
		}
 } 
