/*
    双向DFS
    */
#include<map>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 25;
const int INF = 0x3f3f3f3f;
long long int a[maxn][maxn];
map<long long, long long> mp[maxn];
int n, m;
long long int k;

void dfs(int x, int y, long long s){
    if(x > n || y > m) 
        return;
    if((x + y) == (n + m)/2 + 1){
        mp[x][s^a[x][y]]++;
        return;
    }
    dfs(x+1,y,s^a[x][y]);
    dfs(x,y+1,s^a[x][y]);
}

long long solve(int x, int y, long long s){
    if(x < 1 || y < 1) 
        return 0;
    if((x + y) == (n + m)/2 + 1) 
        return mp[x][s];
    return 
        solve(x-1,y,s^a[x][y])+solve(x,y-1,s^a[x][y]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    dfs(1, 1, 0);
    cout<<solve(n, m, k)<<endl;
    return 0;
}