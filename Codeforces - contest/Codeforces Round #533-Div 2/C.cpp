#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
const int mod = 1e9+7;
int a[maxn];
int k[3];
int dp[maxn][3];

int main(){
    int n, l, r;
    cin>>n>>l>>r;
    k[0] = k[1] = k[2] = (r - l + 1)/3;
    for(int i = 0; i < (r - l + 1)%3; i++){
        k[(l+i)%3]++;
    }
    for(int i = 0; i < 3; i++){
        dp[1][i] = k[i];
        // cout<<"k["<<i<<"] = "<<k[i]<<endl;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            dp[i+1][j] = (1LL*dp[i][0]*k[j]%mod + 1LL*dp[i][1]*k[(2+j)%3]%mod + 1LL*dp[i][2]*k[(1+j)%3]%mod)%mod;
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}