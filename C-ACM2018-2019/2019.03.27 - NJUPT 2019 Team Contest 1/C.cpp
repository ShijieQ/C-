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
const int maxn = 500+5;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int vis[maxn * maxn * 2];

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int r, s, p;
    scanf("%d%d%d", &r, &s, &p);
    int out_x = r + 1, out_y = s + 1;
    int ans = 0, cnt = 0;
    int minn = INF, maxx = -INF;
    for(int i = 1; i <= p; i++){
        int X, Y;
        scanf("%d%d", &X, &Y);
        if(Y > s)   Y++;
        int tim = abs(X - out_x) + abs(Y - out_y);
        vis[tim]++;
        maxx = max(maxx, tim);
        minn = min(minn, tim);
    }
    for(int i = minn; i <= maxx; i++){
        if(!vis[i]){
            if(cnt > 0) cnt--;
        }
        else{
            cnt += vis[i] - 1;
        }
    }
    cout<<maxx+cnt<<endl;
    return 0;
}