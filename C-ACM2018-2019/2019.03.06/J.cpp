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

using namespace std;
const int maxn = 20+10;
const int mod = 9901;
const int INF = 0x3f3f3f3f;
int mp[maxn][maxn];
bool vis[maxn];
long long int ans = INF;
int n;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

void dfs(int k, long long int len, int step){
    // cout<<"step = "<<step<<"  k = "<<k<<endl;
    if(step == n-1){
        ans = len + mp[k][n];
        return ;
    }
    vis[k] = 1;
    pair<int, int> temp[maxn];
    for(int i = 1; i <= n; i++){
        temp[i].first = mp[k][i];
        temp[i].second = i;
    }
    sort(temp+1, temp+1+n, cmp);
    for(int i = 1; i <= n; i++){
        int t = temp[i].second;
        int nex = temp[i].first;
        if(!vis[t] && t != n){
            dfs(t, len+mp[k][t], step+1);
            break;
        }
    }
    return ;
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>mp[i][j];
        }
    }
    // for(int k = 1; k <= n; k++){
    //     for(int i = 1; i <= n; i++){
    //         mp[i][i] = 0;
    //         for(int j = 1; j <= n; j++){
    //             mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
    //         }
    //     }
    // }
    dfs(1, 0, 1);
    cout<<ans<<endl;
    return 0;
}
