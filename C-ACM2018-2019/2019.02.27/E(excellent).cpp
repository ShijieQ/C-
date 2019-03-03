//http://codeforces.com/contest/500/problem/B
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 300+10;
char mp[maxn][maxn];
int n;
int a[maxn];
bool vis[maxn];
vector<int> pos;

void read(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%s", mp[i]);
}

void dfs(int k){
    if(vis[k])
        return ;
    vis[k] = 1;
    pos.push_back(a[k]);
    for(int i = 0; i < n; i++)
        if(mp[k][i] == '1')
            dfs(i);
}

void solve(){
    for(int i = 0; i < n; i++){
        dfs(i);
        sort(pos.begin(), pos.end());
        for(int j = 0, k = 0; j < n; j++)
            if(vis[j])
                a[j] = pos[k++];
        memset(vis, 0, sizeof(vis));
        pos.clear();
    }
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    read();
    solve();
    return 0;
}