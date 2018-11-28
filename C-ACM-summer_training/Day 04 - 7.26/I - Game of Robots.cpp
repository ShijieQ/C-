#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n, k;
	cin>>n>>k;
	int a[100005];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; k > i; i++)
		k -= i;
//	cout<<k<<endl;
	cout<<a[k-1]<<endl;
}
