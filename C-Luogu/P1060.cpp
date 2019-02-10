#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e4+10;
const int INF = 0x3f3f3f3f;
int dp[30][maxn];
int v[30], p[30];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>v[i]>>p[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(v[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i]] + v[i]*p[i]);
            }
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}