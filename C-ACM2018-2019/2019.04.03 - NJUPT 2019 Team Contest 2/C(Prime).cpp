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
#define esp  1e-6
#define Online

using namespace std;
const int maxn = 2e3+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
bool vis[maxn][maxn];

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 > x2)     swap(x1, x2), swap(y1, y2);
        if(x1 == x2 || y1 == y2){
            continue;
        }
        double k = 1.0*(y1 - y2)/(x1 - x2);
        double b = 1.0*y1 - k*x1;
        for(int j = x1; j < x2; j++){
            double y0 = j*k + b;
            double yn = (j+1)*k + b;
            if(k < 0)   swap(y0, yn);
            int y00 = floor(y0 + esp);
            int ynn = ceil(yn - esp);
            for(int tem = y00; tem < ynn; tem++){
                vis[j][tem] = 1;
                // cout<<j<<" "<<x<<endl;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            if(vis[i][j])   ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}