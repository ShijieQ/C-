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

using namespace std;
const int maxn = 1e5+100;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
long long int ans = -INF;
int pos_r[maxn], pos_l[maxn];
long long int a[maxn];

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        long long int k;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        pos_l[1] = 1;
        for(int i = 2; i <= n; i++){
            if(a[i] >= a[i-1]){
                pos_l[i] = pos_l[i-1];
            }
            else{
                pos_l[i] = i;
            }
        }
        pos_r[n] = n;
        for(int i = n-1; i >= 1; i--){
            if(a[i] >= a[i+1]){
                pos_r[i] = pos_r[i+1];
            }
            else{
                pos_r[i] = i;
            }
        }
        for(int i = 1; i <= n; i++){
            cout<<pos_l[i]<<"  "<<pos_r[i]<<endl;
        }
        for(int i = 1; i <= n; i++){
            ans = max(ans, a[i]*(pos_r[i] - pos_l[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}