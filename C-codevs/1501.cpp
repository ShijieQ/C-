#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 16+5;
const int INF = 0x3f3f3f3f;
vector<int> vec[maxn];
int width[maxn+10];
int k = 0;

int dfs(int n, int dep){
	int l = 0, r = 0, ans = 1;
	if(!n){
		ans = 0;
	}
	else{
		width[dep]++;
		l = dfs(vec[n][0], dep+1);
		r = dfs(vec[n][1], dep+1);
		ans += max(l, r);
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int tema, temb;
		scanf("%d%d", &tema, &temb);
		vec[i].push_back(tema);
		vec[i].push_back(temb);
	}
	int heigh = dfs(1, 1);
	int wei = -INF;
	for(int i = 1; i <= n; i++){
		wei = max(wei, width[i]);
	}
	cout<<wei<<" "<<heigh<<endl;
	return 0;
}
/*
5
2 3
4 5
0 0
0 0
0 0
*/