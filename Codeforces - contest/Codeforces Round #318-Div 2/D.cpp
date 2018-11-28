#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
int a[maxn];
int dp[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] > a[i-1]){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = dp[i-1];
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}