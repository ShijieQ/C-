#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 200+7;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn];
int v[maxn];            
int w[maxn];            
bool visited[maxn];    
int squ[maxn];       
int indexs;

int stoer_wagner(int n){
    int min_cut = INF,r=0;
    for (int i = 0; i < n; ++i){
        v[i] = i;        
    }
    
    while (n > 1){
        int pre = 0;    
        memset(visited, 0, sizeof(visited));
        memset(w, 0, sizeof(w));
        for (int i = 1; i < n; ++i){ 
            int k = -1;
            for (int j = 1; j < n; ++j){             
                if (!visited[v[j]]){
                    w[v[j]] += G[v[pre]][v[j]];
                    if (k == -1 || w[v[k]] < w[v[j]]){
                        k = j;
                    }
                }
            }
             
            visited[v[k]] = true;        
            if (i == n - 1){                
                const int s = v[pre], t = v[k];        
                squ[r++]=t;
                if(w[t]<min_cut){
                    min_cut=w[t];
                    indexs=r;
                }
                for (int j = 0; j < n; ++j){            
                    G[s][v[j]] += G[v[j]][t];
                    G[v[j]][s] += G[v[j]][t];
                }
                v[k] = v[--n];                        
            }
            // else 继续
            pre = k;
        }
    }
    return min_cut;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    while(cin>>m>>n){
        memset(G, 0, sizeof(G));
        for(int i = 1; i <= n; i++){
            int x, y;
            char ch;
            cin>>ch>>x>>ch>>y>>ch;
        //    cout<<x<<" "<<y;
            G[x][y] += 1;
            G[y][x] += 1;
        }
        int ans = stoer_wagner(m);
        if(ans == INF)  ans = 0;
        cout<<ans<<endl;
    }
}
/*
0 0
2 1 (0,1)
2 0
5 8 (0,1) (1,3) (2,3) (0,2) (0,1) (2,3) (2,4) (2,4)
*/