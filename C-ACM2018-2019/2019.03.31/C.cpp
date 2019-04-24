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
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
map<string, bool> vis;
string a, b;
string temp, ans;

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int T;
    cin>>T;
    for(int k = 1; k <= T; k++){
        vis.clear();
        int len;
        cin>>len;
        cin>>a>>b>>ans;
        // cout<<a<<endl<<b<<endl<<ans<<endl;
        temp = a + b;
        int cnt = 0;
        int flag = 1;
        while(!vis[temp]){
            vis[temp] = 1;
            cnt++;
            for(int i = 0; i < len; i++){
                temp[2*i]     = b[i];
                temp[2*i + 1] = a[i];
            }
            // cout<<temp<<endl;
            if(temp == ans){
                flag = 0;
                break;
            }
            else{
                a = temp.substr(0, len);
                b = temp.substr(len, len);
            }
        }
        if(flag)    cnt = -1;
        cout<<k<<" "<<cnt<<endl;
    }
    return 0;
}