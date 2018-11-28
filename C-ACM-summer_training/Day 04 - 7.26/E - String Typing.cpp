#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
bool fun(char a[], int k)
{
	for(int i = 0; i < k; i++)
		if(a[i] != a[i+k])
			return false;
	return true;
}
int main()
{
	char a[105];
	int n;
	cin>>n>>a;
	int maxn = 0;
	for(int i = 1; i < n+1/2; i++)
	{
		if(fun(a,i))
			maxn = i;
	}
	if(maxn == 0)
		cout<<strlen(a)<<endl;
	else
		cout<<strlen(a) -maxn +1<<endl;
} 
