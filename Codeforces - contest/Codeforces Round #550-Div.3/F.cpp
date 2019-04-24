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
const int INF = 0x3f3f3f3f;
vector<int> vec[maxn];
int n, m;
int l[maxn], r[maxn];
bool vis[maxn];
int col[maxn];

void dfs(int k, int c){
    col[k] = c;
    vis[k] = 1;
    int siz = vec[k].size();
    for(int i = 0; i < siz; i++){
        if(!vis[vec[k][i]]){
            dfs(vec[k][i], 1 - c);
        }
    }
    return ;
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>l[i]>>r[i];
        vec[l[i]].push_back(r[i]);
        vec[r[i]].push_back(l[i]);
    }
    dfs(1, 1);
    string ans = "";
    for(int i = 1; i <= m; i++){
        if(col[l[i]] == col[r[i]]){
            cout<<"NO"<<endl;
            return 0;
        }
        else if(col[l[i]] == 1){
            ans += '1';
        }
        else{
            ans += '0';
        }
    }
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    return 0;
}