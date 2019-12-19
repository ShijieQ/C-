#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring> 
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> node[200005];
vector<int> v, c;

int judge(int k){
	//用于防止判断已访问节点陷入死循环，注释部分为另一种方法。 
	if(v[k])
		return 1;
	v[k] = 1;
	int siz = node[k].size();
	if(siz != 2)
		return 0;
	for(int i = 0; i < 2; i++){
	/*	if(v[node[k][i]] == 1)
			continue;*/
		if(!judge(node[k][i]))
			return 0;
	}
	return 1;
}

void del(int k){
	//同上 
	if(c[k])
		return;
	c[k] = 1;
	int siz = node[k].size();
	for(int i = 0; i < siz; i++){
	/*	if(c[node[k][i]] == 1)
			continue;*/
		del(node[k][i]);
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	int ai, bi;
	v.resize(n+1);
	c.resize(n+1);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &ai, &bi);
		node[ai].push_back(bi);
		node[bi].push_back(ai);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!c[i]){
			ans += judge(i);
			del(i);
		}
	}
	cout<<ans<<endl;
}
