#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	int n, A, B;
	cin>>n>>A>>B;
	int a[100005];
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if(a[0]*A/sum >= B)
	{
		cout<<"0"<<endl;
		return 0;
	}
	sort(a+1, a+n, cmp);
	int flag = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[0]*A/sum >= B)
			break;
		sum -= a[i];
		flag++;
	}
	cout<<flag<<endl;
}
