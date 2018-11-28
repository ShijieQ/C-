#include<iostream>
#include<algorithm>
#define maxn 200000+5
using namespace std;
int a[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += a[i];
		cout<<ans/m<<" ";
		ans %= m;
	}
}

