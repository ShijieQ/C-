//http://codeforces.com/contest/500/problem/C
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000+10;
int w[maxn], k[maxn];
vector<int> pos;
bool vis[maxn];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>w[i];
    }
    long long int ans = 0;
    for(int i = 1; i <= m; i++){
        cin>>k[i];
        if(!vis[k[i]]){
            pos.push_back(k[i]);
            vis[k[i]] = 1;
        }
    }
    for(int i = 1; i <= m; i++){
        int j = 0;
        while(j < pos.size()){
            if(pos[j] == k[i]){
                pos.erase(pos.begin() + j);
                pos.insert(pos.begin(), k[i]);
                break;
            }
            ans += w[pos[j]];
            j++;
        }
        // reverse(pos.begin(), pos.end());
        // pos.push_back(k[i]);
        // reverse(pos.begin(), pos.end());
    }
    cout<<ans<<endl;
    return 0;
}