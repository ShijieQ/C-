#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 6000+10;
int val[maxn];
vector<int> v[maxn];
int dp[maxn][2];
bool vis[maxn];

void dfs(int root){
    vis[root] = 1;
    int size = v[root].size();
    for(int i = 0; i < size; i++){
        int temp = v[root][i];
        if(!vis[temp]){
            dfs(temp);
            dp[root][1] = dp[root][1] + dp[temp][0];
            dp[root][0] = dp[root][0] + max(dp[temp][0], dp[temp][1]);
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            v[i].clear();
            cin>>dp[i][1];
            dp[i][0] = 0;
        }
        int temp_a, temp_b;
        scanf("%d %d", &temp_a, &temp_b);
        int gra = 0;
        while(temp_a && temp_b){
            v[temp_b].push_back(temp_a);
            v[temp_a].push_back(temp_b);
            gra = temp_b;
            scanf("%d %d", &temp_a, &temp_b);
        }
        dfs(gra);
        cout<<max(dp[gra][1], dp[gra][0])<<endl;
    }
    return 0;
}