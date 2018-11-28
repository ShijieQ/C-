#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define INF 0x3f3f3f3f
#define maxn 100000+5
#define LL long long 
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, k, m;
	cin>>n>>k>>m;
	string a[maxn];
	
	map<string, int> mp;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>mp[a[i]];
	}
	for(int i = 0; i < k; i++){
		int a1[maxn];
		int tem, minn = INF;
		cin>>tem;
		for(int j = 0; j < tem; j++){
			cin>>a1[j];
			if(mp[a[a1[j]]] < minn)
				minn = mp[a[a1[j]]];
		}
		for(int j = 0; j < tem; j++){
			mp[a[a1[j]]] = minn;
		}
	}
	LL ans = 0;
	for(int i = 0; i < m; i++){
		string d;
		cin>>d;
		ans += mp[d];
	}
	cout<<ans<<endl;
}
