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
const int maxn = 1e3+10;
bool vis[maxn];
int a[maxn];

int main(){
    int m, n;
    cin>>m>>n;
    int pos = 0;
    for(int i = 0; i < m; i++){
        a[i] = -1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        cin>>temp;
        if(!vis[temp]){
            cnt++;
            vis[a[pos]] = 0;
            a[pos++] = temp;
            vis[temp] = 1;
            if(pos >= m){
                pos %= m;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
