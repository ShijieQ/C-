#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	int a[200009];
	cin>>n>>k;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	if(a[k-1] == a[k])
		cout<<"-1"<<endl;
	else if(k == 0)
		printf("%d\n",a[0]-1>0?a[0]-1:-1);
	else
		cout<<a[k-1]<<endl;
}
