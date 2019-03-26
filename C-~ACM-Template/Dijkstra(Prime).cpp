const int maxn = 500+10;
const int INF = 0x3f3f3f3f;
int dis[maxn];
int G[maxn][maxn];
bool vis[maxn];
int n, v;

void init(){
    for(int i = 1; i < maxn; i++){
        vis[i] = 0;
        for(int j = 1; j < maxn; j++){
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }
}

void output(){
    for(int i = 1; i <= n; i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}

void solve(int k){
    for(int i = 1; i <= n; i++){
        dis[i] = G[k][i];
    }
    vis[k] = 1;
    for(int i = 1; i <= n-1; i++){
        int minn = INF;
        int pos = -1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dis[j] < minn){
                pos = j;
                minn = dis[j];
            }
        }
        vis[pos] = 1;
        for(int j = 1; j <= n; j++){
            if(dis[j] > dis[pos] + G[pos][j]){
                dis[j] = dis[pos] + G[pos][j];
            }
        }
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