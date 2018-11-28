#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100000+5
using namespace std;
int a[maxn], vis[maxn], t[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int num = 0;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    memset(t, 0, sizeof(t));
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        t[a[i]]++;
        if(t[a[i]] == 1){
            num++;
        }
    }
    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        if(t[a[i]] == 1){
            num--;
        }
        t[a[i]]--;
        if(!vis[a[i]]){
            ans += num;
            vis[a[i]] = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}