#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Online

using namespace std;
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int n;
vector<int> v[maxn];
vector<int> ans;
bool vis[maxn];
bool flag = 1;

void dfs(int k){
    vis[k] = 1;
    if(k == n){
        ans.push_back(k);
        flag = 0;
        return ;
    }
    int siz = v[k].size();
    for(int i = 0; i < siz; i++){
        if(!vis[v[k][i]] && flag){
            dfs(v[k][i]);
        }
    }
    if(!flag)   ans.push_back(k);
    return ;
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        v[temp].push_back(i);
    }
    dfs(1);
    int siz = ans.size();
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < siz; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}