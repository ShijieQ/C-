#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 200+10;
const int INF = 0x3f3f3f3f;
int mp[maxn][maxn];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp[i][j] = INF;
            }
            mp[i][i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int a, b, v;
            scanf("%d%d%d", &a, &b, &v);
            if(mp[a][b] > v){
                mp[a][b] = v;
                mp[b][a] = v;
            }
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mp[i][j] = min(mp[i][k] + mp[k][j], mp[i][j]);
                }
            }
        }
        int a, b;
        scanf("%d%d", &a, &b);
        if(mp[a][b] == INF){
            cout<<"-1"<<endl;
        }
        else{
            cout<<mp[a][b]<<endl;
        }
    }
    return 0;
}