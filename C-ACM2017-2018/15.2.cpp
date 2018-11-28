#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef struct toy
{
	char name[12];
	int weight;
}toy;

int main()
{
	int bweig,n;
	cin>>bweig>>n;
	int sum = 0;
	toy *toys = new toy[n+5];
	for(int i = 1; i <= n; i++)
	{
		scanf("%s %d",toys[i].name, &toys[i].weight);
		sum += toys[i].weight;
	}
	int num;
	cin>>num;
	int boy;
	for(int i = 1; i <= num; i++)
	{
		scanf("%d",&boy);
		boy = bweig - boy/2 - 1;
		if(sum + boy < 0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		else
		{
			int *dp = new int[sum];
			for(int i = 1; i <= sum; i++)
				dp[i] = boy;
			for(int i = 1; i <= n; i++)
				for(int j = )
		}
	}
	
}
