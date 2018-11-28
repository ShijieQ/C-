#include<stdio.h>
int sd[101][505];
void add(int i,int j)
{
	int o;
	for(o=i%500;o<=500;o++)
	{
		if(o==0)
			o=500;
		sd[(i-1)/500][o]+=j;
	}
}
void sub(int i,int j)
{
	int o;
	for(o=i%500;o<=500;o++)
	{
		if(o==0)
			o=500;
		sd[(i-1)/500][o]-=j;
	}
}
void Query(int i,int j)
{
	int a=i%500;
	if(a==0)
		a=500;
	int b=j%500;
	if(b==0)
		b=500;
	if((i-1)/500<(j-1)/500)
	{	
		int num=sd[(i-1)/500][500]-sd[(i-1)/500][a-1];
		int o;
		for(o=(i-1)/500+1;o<(j-1)/500;o++)
			num+=sd[o][500];
		num+=sd[(j-1)/500][b];
		printf("%d\n",num);
	}
	else
		printf("%d\n",sd[(j-1)/500][b]-sd[(i-1)/500][a-1]);
}
int main()
{
	int o,k,l,n,i,j,T;
	char s[10];
	scanf("%d",&T);
	for(o=0;o<T;o++)
	{
		for(k=0;k<105;k++)
			sd[k][0]=0;
		printf("Case %d:\n",o+1);
		scanf("%d",&n);
		for(k=0;k<n/500;k++)
			for(l=1;l<=500;l++)
			{
				scanf("%d",&sd[k][l]);
				sd[k][l]+=sd[k][l-1];
			}
		for(l=1;l<=n%500;l++)
		{
			scanf("%d",&sd[k][l]);
			sd[k][l]+=sd[k][l-1];
		}
		for(;;)
		{
			scanf("%s",s);
			if(s[0]=='Q')
			{
				scanf("%d %d",&i,&j);
				Query(i,j);
			}
			else if(s[0]=='A')
			{
				scanf("%d %d",&i,&j);
				add(i,j);
			}
			else if(s[0]=='S')
			{
				scanf("%d %d",&i,&j);
				sub(i,j);
			}
			else if(s[0]=='E')
				break;
		}
		return 0;
	}
 } 

