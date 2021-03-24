#include<queue>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 500+50;
const int INF = 0x3f3f3f3f;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int dis[maxn];
bool vis[maxn];
int G[maxn][maxn];
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
        G[r][l] = val;
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(int k){
    for(int i = 1; i <= n; i++){
        dis[i] = G[k][i];
    }
    q.push(make_pair(dis[k], k));
    while(!q.empty()){
        pair<int, int> now = q.top();
        q.pop();
        int path = now.first;
        int node = now.second;
        if (vis[node]) {
            continue;
        }
        vis[node] = 1;
        for (int i = 1; i <= n; i++) {
            if (G[node][i] == INF || vis[i]) {
                continue;
            }
            if (G[node][i] != INF && dis[node] + G[node][i] < dis[i]) {
                dis[i] = dis[node] + G[node][i];
            }
            q.push({dis[i], i});
        }
    }
    return;
}

int main() {
    init();
    read();
    // output();
    solve(n);
    for (int i = 1; i <= n; i++) {
        cout<<"i = "<<i<<", dis = "<<dis[i]<<endl;
    }
    return 0;
}
/*
5 7
1 3 3
1 2 3
1 4 2
2 3 1
2 5 2
4 5 10
3 5 1
*/