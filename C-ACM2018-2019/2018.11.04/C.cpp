#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+5;
const int INF = 0x3f3f3f3f;
int t[maxn];

int main(){
    int n, T;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>t[i];
    }
    cin>>T;
    sort(t+1, t+n+1);
    int ans = -INF;
    for(int i = 1; i <= n; i++){
        int cnt = 1;
        int tem = t[i] + T;
        for(int j = i+1; j <= n; j++){
            if(t[j] <= tem){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
    return 0;
}