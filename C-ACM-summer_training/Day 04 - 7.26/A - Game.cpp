#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[1005];
	cin>>n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	if(n%2)
		cout<<a[n/2]<<endl;
	else
		cout<<a[n/2-1]<<endl;
 } 
