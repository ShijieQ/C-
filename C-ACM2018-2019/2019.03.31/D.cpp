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
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int pre[maxn];
int n;

void dfs(int k){
    if(k != 1){
        dfs(pre[k]);
    }
    cout<<k<<" ";
}

int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        scanf("%d", &pre[i]);
    }
    dfs(n);
    cout<<endl;
    return 0;
}