#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2005;
char m[maxn][maxn];
int num = 0;
int n, m;

void dfs(int x, int y, int xr, int yr){
    if(m[x][y] == '*' || x >= n || x < 0 || y >= m || y < 0 || !xr || !yr){
        return ;
    }
    m[x][y] = '*';
    dfs(x+1, y, xr-1)
}

int main(){
    cin>>n>>m;
    int r, c;
    cin>>r>>c;
    int x, y;
    cin>>x>>y;
    for(int i = 0; i < n; i++){
        scanf("%s", m[i]);
    }
}