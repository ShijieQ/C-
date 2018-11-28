#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000+10;
const int INF = 0x3f3f3f3f;
vector<pair<int, int> > road[maxn];
bool vis[maxn];
int aim;
long long int ans = 0;

void dfs(long long int len, int root){
    vis[root] = 1;
    int size = road[root].size();
    for(int i = 0; i < size; i++){
        pair<int, int> temp = road[root][i];
        long long int temp_len = temp.second;
        if(!vis[temp.first]){
            if(len + temp_len > ans){
                ans = len + temp_len;
                aim = temp.first;
            }
            dfs(len + temp_len, temp.first);
        }
    }
}

int main(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int a, b, v;
    while(scanf("%d%d%d", &a, &b, &v) != EOF){
        pair<int, int> temp;
        temp.first = b;
        temp.second = v;
        road[a].push_back(temp);
        temp.first = a;
        road[b].push_back(temp);
    }
    dfs(0, b);
    memset(vis, 0, sizeof(vis));
    dfs(0, aim);
    cout<<ans<<endl;
}