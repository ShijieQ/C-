#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	char x[11]="0123456789";
	char have[11];
	int a,jud,h = 0;
	while(scanf("%d",&a) != EOF && a)
	{
		if(h) 
		{
			printf("\n");
			h++;
		}
		jud = 0;
		for(int i = 1234; i <= 98765; i++)
		{
			int t = a*i;
			if(i > 98765) break;
			if(i < 10000)
				sprintf(have,"%d%d%d",i,0,t);
			else
				sprintf(have,"%d%d",i,t);
			sort(have,have+10);
			if(strcmp(x,have)==0)
			{
				printf("%d / %05d = %d\n",t,i,a);
				jud = 1;
			}
		}
		if(!jud)
			printf("There are no solutions for %d.\n",a);
//		else
//			printf("\n");
	}
//	printf("\n");
}
