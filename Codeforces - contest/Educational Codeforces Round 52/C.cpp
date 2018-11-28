#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;
int h[maxn];
int c[maxn];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    long long int sum = 0;
    int maxx = -INF, minn = INF;
    for(int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
        sum += h[i];
        minn = min(minn, h[i]);
        maxx = max(maxx, h[i]);
    }
    if(minn == maxx){
        cout<<"0"<<endl;
    }
    else{
        // sort(h+1, h+n+1);
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++){
            h[i] -= minn;
            c[h[i]]++;
        }
        for(int i = maxx-minn; i >= 1; i--){
            c[i] += c[i+1];
        }
        // for(int i = 0; i <= maxx-minn; i++){
        //     cout<<i<<" "<<c[i]<<endl;
        // }
        int ans = 1;
        int tem = 0;
        for(int i = maxx-minn; i >= 1; i--){
            if(tem+c[i] > k){
                ans++;
                tem = c[i];
            }
            else{
                tem += c[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}