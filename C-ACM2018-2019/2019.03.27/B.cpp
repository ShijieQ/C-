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
const int maxn = 100;
const int INF = 0x3f3f3f3f;
int a[maxn], vis[maxn], n, len, cnt;

bool cmp(int l, int r){
    return l > r;
}

bool dfs(int num, int real_len, int pre){
    if(num > cnt){
        return true;
    }
    if(real_len == len){
        return dfs(num + 1, 0, 1);
    }
    int fail = 0;
    for(int i = pre; i <= n; i++){
        if(!vis[i] && real_len + a[i] <= len && a[i] != fail){
            vis[i] = 1;
            if(dfs(num, real_len + a[i], i + 1)){
                return true;
            }
            else{
                fail = a[i];
                vis[i] = 0;
                if(real_len == 0 || real_len + a[i] == len){
                    return false;
                }
            }
        }
    }
    return false;
}

int main(){
    while(cin>>n && n){
        int sum = 0, val = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
            val = max(val, a[i]);
        }
        sort(a + 1, a + 1 + n, cmp);
        for(len = val; len <= sum; len++){
            if(sum % len)   
                continue;
            cnt = sum/len;
            memset(vis, 0, sizeof(vis));
            if(dfs(1, 0, 1))
                break;
        }
        cout<<len<<endl;
    }
    return 0;
}