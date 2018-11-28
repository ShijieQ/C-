#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct data
{
	int start;
	int end;
} data;

/* 
int cmp(const void *a ,const void *b)
{
    if((*(data *)a).start==(*(data *)b).start)
          return (*(data *)a).end - (*(data *)b).end;
    return (*(data *)a).start - (*(data *)b).start;
}
*/ 

bool cmp(data a,data b)
{
	return a.start < b.start;
}

data time[500005];
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int HHf,MMf,HHe,MMe;
		for(int i = 0; i < n; i++)
		{ 
			scanf("%d:%d %d:%d",&HHf,&MMf,&HHe,&MMe);
			time[i].start = HHf*60+MMf;
			time[i].end = HHe*60+MMe;
		}
//		qsort(time,n,sizeof(time[0]),cmp);
		sort(time,time+n,cmp);
		int max;
		int tim = time[0].start;
		max = time[0].end;
		for(int i = 1; i < n; i++)
		{
			if(time[i].start >= max)
				tim += time[i].start - max;
			if(time[i].end > max )
				max = time[i].end;
		}
		printf("%d\n",tim + 24*60 - max);
	}
	return 0;
}
