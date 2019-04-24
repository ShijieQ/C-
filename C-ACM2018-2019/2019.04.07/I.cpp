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
const int maxn = 1e5+10;
int vis[maxn];

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int p, e, g, d, num = 0;
    while(scanf("%d%d%d%d", &p, &e, &g, &d) != EOF){
        num++;
        if(p == -1 && e == -1 && g == -1 && d == -1){
            break;
        }
        if(num > 1){
            cout<<endl;
        }
        memset(vis, 0, sizeof(vis));
        cout<<"Case "<<num<<": the next triple peak occurs in ";
        p %= 23, e %= 28, g %= 33;
        for(int i = 0; i*23 + p < maxn; i++){
            vis[i*23 + p]++;
        }
        for(int i = 0; i*28 + e < maxn; i++){
            vis[i*28 + e]++;
        }
        for(int i = 0; i*33 + g < maxn; i++){
            vis[i*33 + g]++;
        }
        bool flag = 0;
        for(int i = d+1; i < maxn; i++){
            if(vis[i] == 3){
                if(i - d > 21252){
                    break;
                }
                cout<<(i - d);
                flag = 1;
                break;
            }
        }
        if(!flag)   cout<<21252;
        cout<<" days.";
    }
    return 0;
}