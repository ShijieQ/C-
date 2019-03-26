#include<queue>
#include<vector>
#include<cstdio>

using namespace std;
const int maxn = 500+50;
const int INF = 0x3f3f3f3f;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int dis[maxn];
bool vis[maxn];
int n, v;

void init(){
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j < maxn; j++){
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }
}

void read(){
    scanf("%d%d", &n, &v);
    for(int i = 1; i <= v; i++){
        int l, r, val;
        scanf("%d%d%d", &l, &r, &val);
        G[l][r] = val;
    }
}

void solve(int k){
    for(int i = 1; i <= n; i++){
        dis[i] = G[k][i];
    }
    q.push(make_pair(dis[k], k));
    vis[k] = 0;
    while(!q.empty()){

    }
}
