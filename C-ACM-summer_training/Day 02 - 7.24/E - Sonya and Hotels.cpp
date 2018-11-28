#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
int main()
{
	int n, d;
	int a[105];
	int point[105][2];
	cin>>n>>d;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		point[i][0] = a[i] - d;
		point[i][1] = a[i] + d;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(point[j][0] != -1000000005 && abs(point[j][0] - a[i]) < d)
				point[j][0] = -1000000005;
			if(point[j][1] != -1000000005 && abs(point[j][1] - a[i]) < d)
				point[j][1] = -1000000005;
		}
	}
	set<int> arr;
	for(int i = 0; i < n; i++)
	{
		arr.insert(point[i][0]);
		arr.insert(point[i][1]);
	}
	int ans = arr.size();
	set<int>::iterator it;
	for(it=arr.begin(); it!=arr.end(); it++) 
    {
		if(*it == -1000000005)
		{
			ans--;
		//	arr.erase(*it);
			break;
		}
	//cout<<*it<<" "<<endl;	
	}
	cout<<ans<<endl;
}
