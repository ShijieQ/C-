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
#define Online

using namespace std;
const int maxn = 5000+100;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int a[maxn];
int dp[maxn][maxn];

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n; 
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dp[i][j] = (i != j ? 2:1);
        }
    }
    int ans = 2;
    for(int i = n - 1; i >= 2; i--){
        int l = i - 1, r = i + 1;
        while(l >= 1 && r <= n){
            if(a[l] + a[r] == 2*a[i]){
                dp[l][i] = dp[i][r] + 1;
                ans = (dp[l][i] > ans ? dp[l][i]:ans);
                l--, r++;
            }
            else if(a[l] + a[r] < 2*a[i]){
                r++;
            }
            else{
                l--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}