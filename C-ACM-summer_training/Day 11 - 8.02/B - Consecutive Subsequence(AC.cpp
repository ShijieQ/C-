#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
#define LL long long
#define maxn 200005  
using namespace std;
int main(){
	map<int, int> mp;
	int n;
	int a[maxn];
	int maxx = 0;
	int pos = 0;
	cin>>n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mp[a[i]] = mp[a[i]-1] + 1;
		if(mp[a[i]] > maxx){
			maxx = mp[a[i]];
			pos = a[i];
		}
	}
	cout<<maxx<<endl;
	int minn = pos-maxx+1;
	for(int i = 1; i <= n; i++){
		if(a[i] == minn){
			cout<<i<<" ";
			minn++;
		}
	}
	cout<<endl;
	return 0;
} 


