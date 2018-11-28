#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#define INF 0x3f3f3f3f
#define maxn 200000+5
using namespace std;
int pre[maxn];
int c[maxn];
vector<int> num[maxn];

int find(int x)                                       
{ 
    int r = x;
    while(pre[r] != r)
        r=pre[r];
    int i = x, j;
    while(i != r){
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void mix(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		pre[fx] = fy;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++){
		cin>>c[i];
		pre[i] = i;
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		cin>>a>>b;
		mix(a, b);
	}
	for(int i = 1; i <= n; i++){
		num[find(i)].push_back(c[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int maxx = -INF;
		int len = num[i].size();
		if(len){
			map<int, int> mp;
			for(int j = 0; j < len; j++){
				mp[num[i][j]]++;
				maxx = max(maxx, mp[num[i][j]]);
			}
			ans += len - maxx;
		}
	}
	cout<<ans<<endl;
}
