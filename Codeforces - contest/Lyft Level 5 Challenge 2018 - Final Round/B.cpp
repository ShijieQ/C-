#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
pair<int, int> a[maxn*2];
int vis[maxn*2];
int ans[maxn*2];

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n+m; i++){
        cin>>a[i].first;
    }
    for(int i = 1; i <= n+m; i++){
        cin>>a[i].second;
    }
    int now = -1;
    for(int i = 1; i <= n+m; i++){
        if(a[i].second){
            now = i;
        }
        else {
            vis[i] = now;
        }
    }
    now = INF;
    for(int i = m+n; i >= 1; i--){
        if(a[i].second){
            now = i;
        }
        else {
            if(now == INF){
                ans[vis[i]]++;
            }
            else if(vis[i] == -1){
                ans[now]++;
            }
            else{
                if (abs(a[now].first - a[i].first) >= abs(a[i].first - a[vis[i]].first)){
                    ans[vis[i]]++;
                }
                else {
                    ans[now]++;
                }
            }
            // if(now != INF && vis[i] != -1)
            //     vis[i] = abs(a[now].first - a[i].first) > abs(a[i].first - a[vis[i]].first) ? now:vis[i];
            // else if(vis[i] == -1){
            //     vis[i] = now;
            // }
        }
    }
    // for(int i = 1; i <= n+m; i++){
    //     ans[vis[i]]++;
    // }
    for(int i = 1; i <= n+m; i++){
        if(a[i].second){
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}