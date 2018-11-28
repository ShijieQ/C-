#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;
//vector<int> vis;
typedef struct a{
//	vector<int> b;
	int d;
	int v;
}a;
/*
void dfs(int k){
	vis[k] = 1;
	int s = node[k].b.size();
	for(int i = 0; i < s; i++){
		
	}
}*/
int main(){
	int T;
	cin>>T;
	while(T--){
		a node[maxn];
		int n;
		cin>>n;
		for(int i = 1; i <= n; i++){
			int a;
			scanf("%d", &a);
			node[i].v = a;
		}
		for(int i = 0; i < n-1; i++){
			int x, y;
			scanf("%d%d", &x, &y);
		/*	node[x].b.push_back(y);
			node[y].b.push_back(x);*/
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans ^= node[i].v;
		}
		if(ans==0){
			cout<<"D"<<endl;
		}
		else
			cout<<"Q"<<endl;
	} 
}
