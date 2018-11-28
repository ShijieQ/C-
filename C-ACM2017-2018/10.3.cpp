#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int l;
	while(scanf("%d",&l) != EOF)
	{
		int maxd = 0;
		int num,maxtimes;
		cin>>num>>maxtimes;
		int *a = new int[num+1];
		a[0] = 0;
		for(int i = 1; i <= num; i++)
			scanf("%d",&a[i]);
		sort(a+1,a+num+1);
		for(int i = 1; i <= num; i++)
			if(a[i]-a[i-1]>maxd)
				maxd=a[i]-a[i-1];
		if(l - a[num]>maxd)
			maxd = l - a[num];
		int i;
		for(i = maxd; i <= l; i++)
		{
			int times = 1;
			int c = 0;
			int j = 1;
			while(j <= num) 
			{
				if(a[j] - c > i)
				{
					times++;
					c = a[j-1];
				}
				if(j == num)
				{
					if(l - c > i)
					{
						times++;
						c = a[j-1];
					}
				}
				j++;
			}
			if(times <= maxtimes)
				break;
		}
		cout<<i<<endl;
	}
}
