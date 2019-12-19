#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
vector<int> v[30];
vector<int> vis;
stack<int> s;
int flag = 0;

void dfs(int k){
	vis[k] = 1;
	for(int i = 0; i < v[k].size(); i++){
		int t = v[k][i];
		if(vis[t] == 1){
			flag = 1;
			break;
		}
		if(vis[t] == 0)
			dfs(t);
	}
	if(flag)
		return;
	vis[k] = -1;//表示char(k+'a')之后无要求
	s.push(k);
}

void pu(){
	while(!s.empty()){
		printf("%c", (s.top()+'a'));
		s.pop();
	}
	cout<<endl;
}

int sol(string a, string b){
	int sig = 0;
	for(int i = 0; i < min(a.size(), b.size()); i++){
		if(a[i] == b[i])
			sig++;
		if(a[i] != b[i]){
			int a1 = a[i] - 'a';
			int b1 = b[i] - 'a';
			v[a1].push_back(b1);
			break;
		}
		if(a.size() > b.size() && sig == b.size()){
			sig = 1;
			return sig;
		}
	}
	return 0;	
}

int main(){
	int n;
	cin>>n;
//	priority_queue<int, vector<int>, cmp> q;
	string a[105];
	vis.resize(30);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n-1; i++){
		if(sol(a[i], a[i+1])){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	for(int i = 25; i >= 0; i--){
		if(!vis[i])
			dfs(i);
		if(flag){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	pu();
	return 0;
} 
