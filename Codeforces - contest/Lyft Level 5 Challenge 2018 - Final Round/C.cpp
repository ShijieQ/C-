#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 1e9;
const int maxn = 1e5+10;
int ver[maxn];
int hor[maxn];
int num = 1;

int main(){
    ios::sync_with_stdio(false);
    int n, m, ans = 0, cnt = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>ver[i];
    }
    sort(ver+1, ver+n+1);
    for(int i = 1; i <= m; i++){
        int x1, x2, y;
        cin>>x1>>x2>>y;
        if(x1 == 1){
            hor[num++] = x2;
            if(x2 == INF){
                cnt++;
            }
        }
    }
    sort(hor+1, hor+num);
    for(int i = 1, j = 1; i <= n && j < num; ){
        if(hor[j] < ver[i]){
            j++;
        }
        else{
            i++;
            j++;
            ans++;
        }
    }
    cout<<max(ans, cnt)<<endl;
    return 0;
}