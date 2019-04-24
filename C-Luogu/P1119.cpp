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
// #define Online

using namespace std;
const int maxn = 200+50;
const int MAX = 5e4+10;
const int INF = 0x3f3f3f3f;
int t[maxn];
int mp[maxn][maxn];
pair<pair<int, int>, int> q[MAX]; 
int n, m;
int ans[MAX];

void init(){
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            mp[i][j] = INF;
        }
        mp[i][i] = 0;
    }
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t[i]);
    }
    for(int i = 1; i <= m; i++){
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        l++, r++;
        mp[l][r] = v;
        mp[r][l] = v;
    }
    int qnum;
    scanf("%d", &qnum);
    for(int i = 1; i <= qnum; i++){
        int l, r, tt;
        scanf("%d%d%d", &l, &r, &tt);
        l++, r++;
        q[i].first.first = l;
        q[i].first.second = r;
        q[i].second = tt;
    }
    int pos = 1, k = 1;
    for(int pos = 1; pos <= qnum; pos++){
        while(k <= n && t[k] <= q[pos].second){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(mp[i][j] > mp[i][k] + mp[k][j]){
                        mp[i][j] = mp[i][k] + mp[k][j];
                        mp[j][i] = mp[i][j];
                    }
                }
            }
            k++;
        }
        int l = q[pos].first.first, r = q[pos].first.second, realt = q[pos].second;
        if(t[l] > realt || t[r] > realt){
            printf("-1\n");
        }
        else{
            printf("%d\n", (mp[l][r] >= INF ? -1:mp[l][r]));
        }
    }
    return 0;
}