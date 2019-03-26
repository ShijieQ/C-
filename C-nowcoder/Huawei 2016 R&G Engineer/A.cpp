#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
 
using namespace std;
const int maxn = 1000+10;
int vis[maxn];
 
int main(){
    int n;
    while(cin>>n){
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        int tim = 0;
        int now = 0;
        for(int i = 0; tim <= n-1; i++){
            if(i > n){
                i %= n;
            }
            if(!vis[i]){
                cnt++;
            }
            if(cnt == 3){
                vis[i] = 1;
                cnt = 0;
                now = i;
                tim++;
            }
        }
        cout<<now<<endl;
    }
    return 0;
}