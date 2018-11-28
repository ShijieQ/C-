#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int num[10000],a,f,x,count = 0;
	while(scanf("%d %d",&a,&f) == 2 && a)
	{
		int i;
		for(i = 0;i < a;i++)
		 scanf("%d",&num[i]);
		sort(num,num+a);
		printf("CASE# %d:\n",++count);
		while(f--)
		{
			scanf("%d",&x);
			int j = lower_bound(num,num+a,x) - num;
			 if(x == num[j])
			  printf("%d found at %d\n",x,j+1);
			 else printf("%d not found\n",x);
		}
	}
	return 0;
 } 
