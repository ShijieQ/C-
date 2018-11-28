#include<algorithm>
#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define maxn 1000+5
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int, int> mp;
	int a[maxn], b[maxn];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	for(int j = 0; j < n; j++){
		scanf("%d", &b[j]);
		mp[b[j]]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int tem = a[i]^b[j];
			if(mp[tem])
				ans++;
		}
	}
	cout<<ans%2<<endl;
}
